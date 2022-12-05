#!/bin/bash -f
# ****************************************************************************
# Vivado (TM) v2020.2 (64-bit)
#
# Filename    : simulate.sh
# Simulator   : Xilinx Vivado Simulator
# Description : Script for simulating the design by launching the simulator
#
# Generated by Vivado on Mon Dec 05 17:07:14 JST 2022
# SW Build 3064766 on Wed Nov 18 09:12:47 MST 2020
#
# Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
#
# usage: simulate.sh
#
# ****************************************************************************
set -Eeuo pipefail
# simulate design
echo "xsim decoder_tb_behav -key {Behavioral:sim_1:Functional:decoder_tb} -tclbatch decoder_tb.tcl -log simulate.log"
xsim decoder_tb_behav -key {Behavioral:sim_1:Functional:decoder_tb} -tclbatch decoder_tb.tcl -log simulate.log

