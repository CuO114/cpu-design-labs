warning: in the working copy of 'miniRV_basic_ego1/miniRV_basic/src/rtl/ALU.v', CRLF will be replaced by LF the next time Git touches it
warning: in the working copy of 'miniRV_basic_ego1/miniRV_basic/src/rtl/defines.vh', CRLF will be replaced by LF the next time Git touches it
[1mdiff --git "a/homework/\346\225\260\346\215\256\351\200\232\350\267\257\350\241\250\343\200\201\346\216\247\345\210\266\344\277\241\345\217\267\345\217\226\345\200\274\350\241\250_miniRV - \346\250\241\346\235\277.xlsx" "b/homework/\346\225\260\346\215\256\351\200\232\350\267\257\350\241\250\343\200\201\346\216\247\345\210\266\344\277\241\345\217\267\345\217\226\345\200\274\350\241\250_miniRV - \346\250\241\346\235\277.xlsx"[m
[1mdeleted file mode 100644[m
[1mindex 517125d..0000000[m
Binary files "a/homework/\346\225\260\346\215\256\351\200\232\350\267\257\350\241\250\343\200\201\346\216\247\345\210\266\344\277\241\345\217\267\345\217\226\345\200\274\350\241\250_miniRV - \346\250\241\346\235\277.xlsx" and /dev/null differ
[1mdiff --git a/miniRV_basic_ego1/miniRV_basic/dfx_runtime.txt b/miniRV_basic_ego1/miniRV_basic/dfx_runtime.txt[m
[1mindex bf395b6..295149c 100644[m
[1m--- a/miniRV_basic_ego1/miniRV_basic/dfx_runtime.txt[m
[1m+++ b/miniRV_basic_ego1/miniRV_basic/dfx_runtime.txt[m
[36m@@ -1,2 +1,2 @@[m
 DFXRuntime Profile Report:[m
[31m-Total Application(DFX) Runtime :                  CPU : 0:3:22 WALL : 0:0:0  0.00 % [m
[32m+[m[32mTotal Application(DFX) Runtime :                  CPU : 0:0:2 WALL : 0:0:0  0.00 %[m[41m [m
[1mdiff --git a/miniRV_basic_ego1/miniRV_basic/miniRV.xpr b/miniRV_basic_ego1/miniRV_basic/miniRV.xpr[m
[1mindex 6056ba9..7d61f31 100644[m
[1m--- a/miniRV_basic_ego1/miniRV_basic/miniRV.xpr[m
[1m+++ b/miniRV_basic_ego1/miniRV_basic/miniRV.xpr[m
[36m@@ -58,20 +58,20 @@[m
     <Option Name="IPUserFilesDir" Val="$PIPUSERFILESDIR"/>[m
     <Option Name="IPStaticSourceDir" Val="$PIPUSERFILESDIR/ipstatic"/>[m
     <Option Name="EnableBDX" Val="FALSE"/>[m
[31m-    <Option Name="WTXSimLaunchSim" Val="1606"/>[m
[32m+[m[32m    <Option Name="WTXSimLaunchSim" Val="1610"/>[m
     <Option Name="WTModelSimLaunchSim" Val="0"/>[m
     <Option Name="WTQuestaLaunchSim" Val="0"/>[m
     <Option Name="WTIesLaunchSim" Val="0"/>[m
     <Option Name="WTVcsLaunchSim" Val="0"/>[m
     <Option Name="WTRivieraLaunchSim" Val="0"/>[m
     <Option Name="WTActivehdlLaunchSim" Val="0"/>[m
[31m-    <Option Name="WTXSimExportSim" Val="267"/>[m
[31m-    <Option Name="WTModelSimExportSim" Val="267"/>[m
[31m-    <Option Name="WTQuestaExportSim" Val="267"/>[m
[32m+[m[32m    <Option Name="WTXSimExportSim" Val="270"/>[m
[32m+[m[32m    <Option Name="WTModelSimExportSim" Val="270"/>[m
[32m+[m[32m    <Option Name="WTQuestaExportSim" Val="270"/>[m
     <Option Name="WTIesExportSim" Val="91"/>[m
     <Option Name="WTVcsExportSim" Val="266"/>[m
[31m-    <Option Name="WTRivieraExportSim" Val="266"/>[m
[31m-    <Option Name="WTActivehdlExportSim" Val="266"/>[m
[32m+[m[32m    <Option Name="WTRivieraExportSim" Val="269"/>[m
[32m+[m[32m    <Option Name="WTActivehdlExportSim" Val="269"/>[m
     <Option Name="GenerateIPUpgradeLog" Val="TRUE"/>[m
     <Option Name="XSimRadix" Val="hex"/>[m
     <Option Name="XSimTimeUnit" Val="ns"/>[m
[36m@@ -90,27 +90,6 @@[m
   <FileSets Version="1" Minor="32">[m
     <FileSet Name="sources_1" Type="DesignSrcs" RelSrcDir="$PSRCDIR/sources_1" RelGenDir="$PGENDIR/sources_1">[m
       <Filter Type="Srcs"/>[m
[31m-      <File Path="$PPRDIR/src/rtl/ip/DRAM/DRAM.xci">[m
[31m-        <FileInfo>[m
[31m-          <Attr Name="UsedIn" Val="synthesis"/>[m
[31m-          <Attr Name="UsedIn" Val="implementation"/>[m
[31m-          <Attr Name="UsedIn" Val="simulation"/>[m
[31m-        </FileInfo>[m
[31m-      </File>[m
[31m-      <File Path="$PPRDIR/src/rtl/ip/IROM/IROM.xci">[m
[31m-        <FileInfo>[m
[31m-          <Attr Name="UsedIn" Val="synthesis"/>[m
[31m-          <Attr Name="UsedIn" Val="implementation"/>[m
[31m-          <Attr Name="UsedIn" Val="simulation"/>[m
[31m-        </FileInfo>[m
[31m-      </File>[m
[31m-      <File Path="$PPRDIR/src/rtl/ip/clk_wiz_0/clk_wiz_0.xci">[m
[31m-        <FileInfo>[m
[31m-          <Attr Name="UsedIn" Val="synthesis"/>[m
[31m-          <Attr Name="UsedIn" Val="implementation"/>[m
[31m-          <Attr Name="UsedIn" Val="simulation"/>[m
[31m-        </FileInfo>[m
[31m-      </File>[m
       <File Path="$PPRDIR/src/rtl/ALU.v">[m
         <FileInfo>[m
           <Attr Name="UsedIn" Val="synthesis"/>[m
[36m@@ -320,6 +299,45 @@[m
         <Option Name="TopAutoSet" Val="TRUE"/>[m
       </Config>[m
     </FileSet>[m
[32m+[m[32m    <FileSet Name="DRAM" Type="BlockSrcs" RelSrcDir="$PSRCDIR/DRAM" RelGenDir="$PGENDIR/DRAM">[m
[32m+[m[32m      <File Path="$PPRDIR/src/rtl/ip/DRAM/DRAM.xci">[m
[32m+[m[32m        <FileInfo>[m
[32m+[m[32m          <Attr Name="UsedIn" Val="synthesis"/>[m
[32m+[m[32m          <Attr Name="UsedIn" Val="implementation"/>[m
[32m+[m[32m          <Attr Name="UsedIn" Val="simulation"/>[m
[32m+[m[32m        </FileInfo>[m
[32m+[m[32m      </File>[m
[32m+[m[32m      <Config>[m
[32m+[m[32m        <Option Name="TopModule" Val="DRAM"/>[m
[32m+[m[32m        <Option Name="UseBlackboxStub" Val="1"/>[m
[32m+[m[32m      </Config>[m
[32m+[m[32m    </FileSet>[m
[32m+[m[32m    <FileSet Name="IROM" Type="BlockSrcs" RelSrcDir="$PSRCDIR/IROM" RelGenDir="$PGENDIR/IROM">[m
[32m+[m[32m      <File Path="$PPRDIR/src/rtl/ip/IROM/IROM.xci">[m
[32m+[m[32m        <FileInfo>[m
[32m+[m[32m          <Attr Name="UsedIn" Val="synthesis"/>[m
[32m+[m[32m          <Attr Name="UsedIn" Val="implementation"/>[m
[32m+[m[32m          <Attr Name="UsedIn" Val="simulation"/>[m
[32m+[m[32m        </FileInfo>[m
[32m+[m[32m      </File>[m
[32m+[m[32m      <Config>[m
[32m+[m[32m        <Option Name="TopModule" Val="IROM"/>[m
[32m+[m[32m        <Option Name="UseBlackboxStub" Val="1"/>[m
[32m+[m[32m      </Config>[m
[32m+[m[32m    </FileSet>[m
[32m+[m[32m    <FileSet Name="clk_wiz_0" Type="BlockSrcs" RelSrcDir="$PSRCDIR/clk_wiz_0" RelGenDir="$PGENDIR/clk_wiz_0">[m
[32m+[m[32m      <File Path="$PPRDIR/src/rtl/ip/clk_wiz_0/clk_wiz_0.xci">[m
[32m+[m[32m        <FileInfo>[m
[32m+[m[32m          <Attr Name="UsedIn" Val="synthesis"/>[m
[32m+[m[32m          <Attr Name="UsedIn" Val="implementation"/>[m
[32m+[m[32m          <Attr Name="UsedIn" Val="simulation"/>[m
[32m+[m[32m        </FileInfo>[m
[32m+[m[32m      </File>[m
[32m+[m[32m      <Config>[m
[32m+[m[32m        <Option Name="TopModule" Val="clk_wiz_0"/>[m
[32m+[m[32m        <Option Name="UseBlackboxStub" Val="1"/>[m
[32m+[m[32m      </Config>[m
[32m+[m[32m    </FileSet>[m
   </FileSets>[m
   <Simulators>[m
     <Simulator Name="XSim">[m
[36m@@ -349,6 +367,42 @@[m
       <Report Name="ROUTE_DESIGN.REPORT_METHODOLOGY" Enabled="1"/>[m
       <RQSFiles/>[m
     </Run>[m
[32m+[m[32m    <Run Id="DRAM_synth_1" Type="Ft3:Synth" SrcSet="DRAM" Part="xc7a35tcsg324-1" ConstrsSet="DRAM" Description="Vivado Synthesis Defaults" AutoIncrementalCheckpoint="false" WriteIncrSynthDcp="false" Dir="$PRUNDIR/DRAM_synth_1" IncludeInArchive="true" IsChild="false" AutoIncrementalDir="$PSRCDIR/utils_1/imports/DRAM_synth_1" AutoRQSDir="$PSRCDIR/utils_1/imports/DRAM_synth_1" ParallelReportGen="true">[m
[32m+[m[32m      <Strategy Version="1" Minor="2">[m
[32m+[m[32m        <StratHandle Name="Vivado Synthesis Defaults" Flow="Vivado Synthesis 2025">[m
[32m+[m[32m          <Desc>Vivado Synthesis Defaults</Desc>[m
[32m+[m[32m        </StratHandle>[m
[32m+[m[32m        <Step Id="synth_design"/>[m
[32m+[m[32m      </Strategy>[m
[32m+[m[32m      <GeneratedRun Dir="$PRUNDIR" File="gen_run.xml"/>[m
[32m+[m[32m      <ReportStrategy Name="Vivado Synthesis Default Reports" Flow="Vivado Synthesis 2025"/>[m
[32m+[m[32m      <Report Name="ROUTE_DESIGN.REPORT_METHODOLOGY" Enabled="1"/>[m
[32m+[m[32m      <RQSFiles/>[m
[32m+[m[32m    </Run>[m
[32m+[m[32m    <Run Id="IROM_synth_1" Type="Ft3:Synth" SrcSet="IROM" Part="xc7a35tcsg324-1" ConstrsSet="IROM" Description="Vivado Synthesis Defaults" AutoIncrementalCheckpoint="false" WriteIncrSynthDcp="false" Dir="$PRUNDIR/IROM_synth_1" IncludeInArchive="true" IsChild="false" AutoIncrementalDir="$PSRCDIR/utils_1/imports/IROM_synth_1" AutoRQSDir="$PSRCDIR/utils_1/imports/IROM_synth_1" ParallelReportGen="true">[m
[32m+[m[32m      <Strategy Version="1" Minor="2">[m
[32m+[m[32m        <StratHandle Name="Vivado Synthesis Defaults" Flow="Vivado Synthesis 2025">[m
[32m+[m[32m          <Desc>Vivado Synthesis Defaults</Desc>[m
[32m+[m[32m        </StratHandle>[m
[32m+[m[32m        <Step Id="synth_design"/>[m
[32m+[m[32m      </Strategy>[m
[32m+[m[32m      <GeneratedRun Dir="$PRUNDIR" File="gen_run.xml"/>[m
[32m+[m[32m      <ReportStrategy Name="Vivado Synthesis Default Reports" Flow="Vivado Synthesis 2025"/>[m
[32m+[m[32m      <Report Name="ROUTE_DESIGN.REPORT_METHODOLOGY" Enabled="1"/>[m
[32m+[m[32m      <RQSFiles/>[m
[32m+[m[32m    </Run>[m
[32m+[m[32m    <Run Id="clk_wiz_0_synth_1" Type="Ft3:Synth" SrcSet="clk_wiz_0" Part="xc7a35tcsg324-1" ConstrsSet="clk_wiz_0" Description="Vivado Synthesis Defaults" AutoIncrementalCheckpoint="false" WriteIncrSynthDcp="false" Dir="$PRUNDIR/clk_wiz_0_synth_1" IncludeInArchive="true" IsChild="false" AutoIncrementalDir="$PSRCDIR/utils_1/imports/clk_wiz_0_synth_1" AutoRQSDir="$PSRCDIR/utils_1/imports/clk_wiz_0_synth_1" ParallelReportGen="true">[m
[32m+[m[32m      <Strategy Version="1" Minor="2">[m
[32m+[m[32m        <StratHandle Name="Vivado Synthesis Defaults" Flow="Vivado Synthesis 2025">[m
[32m+[m[32m          <Desc>Vivado Synthesis Defaults</Desc>[m
[32m+[m[32m        </StratHandle>[m
[32m+[m[32m        <Step Id="synth_design"/>[m
[32m+[m[32m      </Strategy>[m
[32m+[m[32m      <GeneratedRun Dir="$PRUNDIR" File="gen_run.xml"/>[m
[32m+[m[32m      <ReportStrategy Name="Vivado Synthesis Default Reports" Flow="Vivado Synthesis 2025"/>[m
[32m+[m[32m      <Report Name="ROUTE_DESIGN.REPORT_METHODOLOGY" Enabled="1"/>[m
[32m+[m[32m      <RQSFiles/>[m
[32m+[m[32m    </Run>[m
     <Run Id="impl_1" Type="Ft2:EntireDesign" Part="xc7a35tcsg324-1" ConstrsSet="constrs_1" Description="Default settings for Implementation." AutoIncrementalCheckpoint="false" WriteIncrSynthDcp="false" State="current" SynthRun="synth_1" IncludeInArchive="true" IsChild="false" GenFullBitstream="true" AutoIncrementalDir="$PSRCDIR/utils_1/imports/impl_1" LaunchOptions="-jobs 16 " AutoRQSDir="$PSRCDIR/utils_1/imports/impl_1" ParallelReportGen="true">[m
       <Strategy Version="1" Minor="2">[m
         <StratHandle Name="Vivado Implementation Defaults" Flow="Vivado Implementation 2018"/>[m
[36m@@ -366,6 +420,63 @@[m
       <Report Name="ROUTE_DESIGN.REPORT_METHODOLOGY" Enabled="1"/>[m
       <RQSFiles/>[m
     </Run>[m
[32m+[m[32m    <Run Id="DRAM_impl_1" Type="Ft2:EntireDesign" Part="xc7a35tcsg324-1" ConstrsSet="DRAM" Description="Default settings for Implementation." AutoIncrementalCheckpoint="false" WriteIncrSynthDcp="false" SynthRun="DRAM_synth_1" IncludeInArchive="false" IsChild="false" GenFullBitstream="true" AutoIncrementalDir="$PSRCDIR/utils_1/imports/DRAM_impl_1" AutoRQSDir="$PSRCDIR/utils_1/imports/DRAM_impl_1" ParallelReportGen="true">[m
[32m+[m[32m      <Strategy Version="1" Minor="2">[m
[32m+[m[32m        <StratHandle Name="Vivado Implementation Defaults" Flow="Vivado Implementation 2025">[m
[32m+[m[32m          <Desc>Default settings for Implementation.</Desc>[m
[32m+[m[32m        </StratHandle>[m
[32m+[m[32m        <Step Id="init_design"/>[m
[32m+[m[32m        <Step Id="opt_design"/>[m
[32m+[m[32m        <Step Id="power_opt_design"/>[m
[32m+[m[32m        <Step Id="place_design"/>[m
[32m+[m[32m        <Step Id="post_place_power_opt_design"/>[m
[32m+[m[32m        <Step Id="phys_opt_design"/>[m
[32m+[m[32m        <Step Id="route_design"/>[m
[32m+[m[32m        <Step Id="post_route_phys_opt_design"/>[m
[32m+[m[32m        <Step Id="write_bitstream"/>[m
[32m+[m[32m      </Strategy>[m
[32m+[m[32m      <ReportStrategy Name="Vivado Implementation Default Reports" Flow="Vivado Implementation 2025"/>[m
[32m+[m[32m      <Report Name="ROUTE_DESIGN.REPORT_METHODOLOGY" Enabled="1"/>[m
[32m+[m[32m      <RQSFiles/>[m
[32m+[m[32m    </Run>[m
[32m+[m[32m    <Run Id="IROM_impl_1" Type="Ft2:EntireDesign" Part="xc7a35tcsg324-1" ConstrsSet="IROM" Description="Default settings for Implementation." AutoIncrementalCheckpoint="false" WriteIncrSynthDcp="false" SynthRun="IROM_synth_1" IncludeInArchive="false" IsChild="false" GenFullBitstream="true" AutoIncrementalDir="$PSRCDIR/utils_1/imports/IROM_impl_1" AutoRQSDir="$PSRCDIR/utils_1/imports/IROM_impl_1" ParallelReportGen="true">[m
[32m+[m[32m      <Strategy Version="1" Minor="2">[m
[32m+[m[32m        <StratHandle Name="Vivado Implementation Defaults" Flow="Vivado Implementation 2025">[m
[32m+[m[32m          <Desc>Default settings for Implementation.</Desc>[m
[32m+[m[32m        </StratHandle>[m
[32m+[m[32m        <Step Id="init_design"/>[m
[32m+[m[32m        <Step Id="opt_design"/>[m
[32m+[m[32m        <Step Id="power_opt_design"/>[m
[32m+[m[32m        <Step Id="place_design"/>[m
[32m+[m[32m        <Step Id="post_place_power_opt_design"/>[m
[32m+[m[32m        <Step Id="phys_opt_design"/>[m
[32m+[m[32m        <Step Id="route_design"/>[m
[32m+[m[32m        <Step Id="post_route_phys_opt_design"/>[m
[32m+[m[32m        <Step Id="write_bitstream"/>[m
[32m+[m[32m      </Strategy>[m
[32m+[m[32m      <ReportStrategy Name="Vivado Implementation Default Reports" Flow="Vivado Implementation 2025"/>[m
[32m+[m[32m      <Report Name="ROUTE_DESIGN.REPORT_METHODOLOGY" Enabled="1"/>[m
[32m+[m[32m      <RQSFiles/>[m
[32m+[m[32m    </Run>[m
[32m+[m[32m    <Run Id="clk_wiz_0_impl_1" Type="Ft2:EntireDesign" Part="xc7a35tcsg324-1" ConstrsSet="clk_wiz_0" Description="Default settings for Implementation." AutoIncrementalCheckpoint="false" WriteIncrSynthDcp="false" SynthRun="clk_wiz_0_synth_1" IncludeInArchive="false" IsChild="false" GenFullBitstream="true" AutoIncrementalDir="$PSRCDIR/utils_1/imports/clk_wiz_0_impl_1" AutoRQSDir="$PSRCDIR/utils_1/imports/clk_wiz_0_impl_1" ParallelReportGen="true">[m
[32m+[m[32m      <Strategy Version="1" Minor="2">[m
[32m+[m[32m        <StratHandle Name="Vivado Implementation Defaults" Flow="Vivado Implementation 2025">[m
[32m+[m[32m          <Desc>Default settings for Implementation.</Desc>[m
[32m+[m[32m        </StratHandle>[m
[32m+[m[32m        <Step Id="init_design"/>[m
[32m+[m[32m        <Step Id="opt_design"/>[m
[32m+[m[32m        <Step Id="power_opt_design"/>[m
[32m+[m[32m        <Step Id="place_design"/>[m
[32m+[m[32m        <Step Id="post_place_power_opt_design"/>[m
[32m+[m[32m        <Step Id="phys_opt_design"/>[m
[32m+[m[32m        <Step Id="route_design"/>[m
[32m+[m[32m        <Step Id="post_route_phys_opt_design"/>[m
[32m+[m[32m        <Step Id="write_bitstream"/>[m
[32m+[m[32m      </Strategy>[m
[32m+[m[32m      <ReportStrategy Name="Vivado Implementation Default Reports" Flow="Vivado Implementation 2025"/>[m
[32m+[m[32m      <Report Name="ROUTE_DESIGN.REPORT_METHODOLOGY" Enabled="1"/>[m
[32m+[m[32m      <RQSFiles/>[m
[32m+[m[32m    </Run>[m
   </Runs>[m
   <Board/>[m
   <DashboardSummary Version="1" Minor="0">[m
[1mdiff --git a/miniRV_basic_ego1/miniRV_basic/src/rtl/ALU.v b/miniRV_basic_ego1/miniRV_basic/src/rtl/ALU.v[m
[1mindex 3ca5976..e70fa18 100644[m
[1m--- a/miniRV_basic_ego1/miniRV_basic/src/rtl/ALU.v[m
[1m+++ b/miniRV_basic_ego1/miniRV_basic/src/rtl/ALU.v[m
[36m@@ -28,6 +28,7 @@[m [mmodule ALU ([m
             `ALU_ADD  : c = a + b;[m
             `ALU_OR   : c = a | b;[m
             `ALU_SLL  : c = a << b[4:0];[m
[32m+[m[32m            `ALU_SUB  : c = a - b;[m
             default   : c = 32'h0;[m
         endcase[m
     end[m
[1mdiff --git a/miniRV_basic_ego1/miniRV_basic/src/rtl/Controller.v b/miniRV_basic_ego1/miniRV_basic/src/rtl/Controller.v[m
[1mindex 8f53617..f28c0a5 100644[m
[1m--- a/miniRV_basic_ego1/miniRV_basic/src/rtl/Controller.v[m
[1m+++ b/miniRV_basic_ego1/min