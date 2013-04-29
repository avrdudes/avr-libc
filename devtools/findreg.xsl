<?xml version="1.0" encoding='UTF-8' ?>
<xsl:stylesheet version="1.0"
                xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
                xmlns="http://www.w3.org/1999/xhtml">
<!--
 * Copyright (c) 2013 Joerg Wunsch
 *
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Joerg Wunsch wrote this file.  As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return.        Joerg Wunsch
 *
 * $Id$
-->

<!--
 * Extract IO register names and offsets out of Atmel Studio 6.x device XML files.
 *
 * The result is one line per IO register, in the form:
 *
 * REGNAME<tab>BASEADDRESS<tab>OFFSET<tab>SIZE<newline>
 *
 * REGNAME     - name of this IO register
 * BASEADDRESS - base address of register group (IO module)
 *               always 0 for non-Xmega devices
 * OFFSET      - offset of register within group
 * SIZE        - size of register in bytes (1 or 2)
-->

<!--
 * Usage:
 *
 * xsltproc findreg.xsl ATxxx.xml > ATxxx.reg.txt
 *
 * or:
 *
 * java -jar /path/to/saxon9.jar -xsl:findreg.xsl -o:ATxxx.reg.txt ATxxx.xml
 *
 * (The warning about Saxon being an XSL 2.0 processor processing a 1.0
 * style sheet can be ignoroed.)
-->
    <xsl:output method="text"/>

    <xsl:template match="//address-space[@name='eeprom']">
	<xsl:value-of select="@name" />
	<xsl:text>&#9;0&#9;</xsl:text>
	<xsl:value-of select="@start" />
	<xsl:text>&#9;</xsl:text>
	<xsl:value-of select="@size" />
	<xsl:text>&#10;</xsl:text>
    </xsl:template>
    <!--
	Pick all register-groups which are located in the
	address-space named "data".  Lock and fuse bits are also
	declared as register-group, but they've got their own address
	space so we can distinguish them from the normal IO registers
	we are interested in here.
    -->
    <xsl:template match="//peripherals//register-group[@address-space='data']">

      <!-- remember for later, since we need the group offset later on -->
      <xsl:variable name="group" select="current()" />
      <xsl:variable name="registergroup"
		    select="//modules/module/register-group[@name=$group/@name-in-module]" />

      <!-- now, iterate over all registers of this group -->
      <xsl:for-each select="$registergroup/register">

	<!--
	    On Xmega devices, prepend the name of the register-group
	    (aka. subsystem) to the register name, since the register
	    names are not unique across the device.

	    On tiny/mega AVR devices, register names are unique across
	    the entire device, so this is not needed/used.
	-->
	<xsl:if test="//device/@architecture='AVR8_XMEGA'">
	  <xsl:value-of select="$group/@name" />
	  <xsl:text>_</xsl:text>
	</xsl:if>
	<xsl:value-of select="@name" />
	<xsl:text>&#9;</xsl:text>
	<xsl:value-of select="$group/@offset" />
	<xsl:text>&#9;</xsl:text>
	<xsl:value-of select="@offset" />
	<xsl:text>&#9;</xsl:text>
	<xsl:value-of select="@size" />
	<xsl:text>&#10;</xsl:text>
      </xsl:for-each>

    </xsl:template>

    <xsl:template match="node()">
      <xsl:apply-templates />
    </xsl:template>

    <xsl:template match="/">
      <xsl:apply-templates />
    </xsl:template>

</xsl:stylesheet>
