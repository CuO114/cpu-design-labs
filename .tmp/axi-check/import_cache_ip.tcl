open_project {D:/cpu-design/miniRV-with-SoC/miniRV.xpr}
import_ip -srcset sources_1 -files {D:/organ_lab3/miniRV_axi_stu/miniRV_axi.srcs/sources_1/ip/blk_mem_gen_1/blk_mem_gen_1.xci}
generate_target all [get_ips blk_mem_gen_1]
save_project
close_project
exit
