#!/usr/bin/perl
# ----------------------------------------------------------------------------
# "THE BEER-WARE LICENSE" (Revision 42):
# <joerg@FreeBSD.ORG> wrote this file.  As long as you retain this notice you
# can do whatever you want with this stuff. If we meet some day, and you think
# this stuff is worth it, you can buy me a beer in return.        Joerg Wunsch
# ----------------------------------------------------------------------------
#
# Parse the generated tree.js file, and insert a <noscript> tree into the
# HTML source.
#
# $Id$
#

die "usage: unjs tree.js tree.html index.html" unless $#ARGV == 2;

$treejs = $ARGV[0];
$treehtml = $ARGV[1];
$indexhtml = $ARGV[2];

parsejs($treejs) || exit 1;

open(HTML, $treehtml) || die "Cannot open $treehtml: $!\n";
open(NEW, ">${treehtml}.new") ||
    die "Cannot create ${treehtml}.new: $!\n";

while (<HTML>) {
    print NEW;
    if (/^<\/script>$/) {
	print NEW "<noscript>\n";
	print NEW $nojs;
	print NEW "</noscript>\n";
    }
}
close(NEW);
close(HTML);
rename($treehtml, "${treehtml}.bak") &&
    rename("${treehtml}.new", $treehtml);

open(HTML, $indexhtml) || die "Cannot open $indexhtml: $!\n";
open(NEW, ">${indexhtml}.new") ||
    die "Cannot create ${indexhtml}.new: $!\n";

while (<HTML>) {
    print NEW;
    if (/^<\/frameset>$/) {
	print NEW "<noframes>\n";
	print NEW $nojs;
	print NEW "</noframes>\n";
    }
}
close(NEW);
close(HTML);
rename($indexhtml, "${indexhtml}.bak") &&
    rename("${indexhtml}.new", $indexhtml);
exit(0);

sub parsejs
{
    my ($f) = @_;
    my ($i, $err);

    open(JS, $f) || die "Cannot open $f: $!\n";

    while ($l = <JS>) {
	chomp $l;

	$resvar = undef;
	$insvar = undef;

	$l =~ s/^\s+//;
	if ($l =~ /^([A-Za-z][A-Za-z0-9]*)\s*=\s*/) {
	    # variable assignment
	    $resvar = $1;
	    $l = $';
	}
	$i = parsefun($l);
	if ($i == 0) {
	    $errs++;
	    next;
	}
    }
    close(JS);
    return $errs == 0;
}

sub parsefun
{
    my ($line) = @_;
    my $fun, $arg;

    if ($line !~ /^([A-Za-z]+)[(](.*)[)]$/) {
	warn "item ignored: $line\n";
	return 0;
    }
    $fun = $1;
    $arg = $2;
    if ($fun ne "gFld" && $fun ne "gLnk" &&
	$fun ne "insFld" && $fun ne "insDoc") {
	warn "function $fun unknown\n";
	return 0;
    }
    if ($fun =~ /^ins(.*)/) {
	parseins($1, $arg) || return 0;
    } elsif ($fun =~ /^g(.*)/) {
	parseg($1, $arg) || return 0;
    }

    return 1;
}

sub parseg
{
    my ($name, $line) = @_;

    if ($line !~ /^["](.*)["],\s*["](.*)["],\s*["](.*)["]/) {
	warn "arglist expected: $line\n";
	return 0;
    }
    $text = $1;
    $tag = $2;
    $lnk = $3;

    if ($name eq "Fld") {
	if ($lnk ne "") {
	    $nojs .= "<a href=\"$lnk\" target=\"basefrm\"><b>$text</b></a><br>\n";
	} else {
	    $nojs .= "$text<br>\n";
	}
    } else {
	# gLnk
	if ($lnk ne "") {
	    $nojs .= "<a href=\"$lnk\" target=\"basefrm\">$text</a><br>\n";
	} else {
	    # Huh, link without target?
	    $nojs .= "$text<br>\n";
	}
    }
}

sub parseins
{
    my ($name, $line) = @_;

    if ($line !~ /^([A-Za-z][A-Za-z0-9]*),\s*/) {
	warn "variable expected: $line\n";
	return;
    }
    $insvar = $1;

    parsefun($') || return 0;

    return 1;
}
	
