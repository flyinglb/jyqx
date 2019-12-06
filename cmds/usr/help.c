// help.c

#include <ansi.h>;
inherit F_CLEAN_UP;

string *default_search = ({"/doc/help/", "/doc/skill/",});
string *wizard_search = ({"/doc/wiz/", "/doc/build/", "/doc/efuns/",});

int main(object me, string arg)
{
        int i;
        string file, map;
        string *search;

        // If no topic specified, give the topics.
        if( !arg ) {
//              cat(HELP_DIR + "help/topics");
 map = "                "HBBLU+HIW"㊣《金庸群侠传》帮助文件 ㊣ (2000.09.12.版) \n"NOR;
 map += "\n"NOR;
 map += HIY" 【游戏概况】\n"NOR;
 map += HIR" ◇"HIW"intro          "HIG"《金庸群侠传》简介    "NOR;
 map += HIR" ◇"HIW"maps           "HIG"《金庸群侠传》地图册  \n"NOR;
 map += HIR" ◇"HIW"newbie         "HIG"《金庸群侠传》新手指南"NOR;
 map += HIR" ◇"HIW"news           "HIG"《金庸群侠传》新增内容\n"NOR;
 map += HIR" ◇"HIW"rules          "HIG"《金庸群侠传》玩家规则"NOR;
 map += HIR" ◇"HIW"wiz_rules      "HIG"《金庸群侠传》巫师规则\n"NOR;
 map += HIR" ◇"HIW"settings       "HIG"环境变量设置          "NOR;
 map += HIR" ◇"HIW"gift_char      "HIG"天赋属性关系图        \n"NOR;
 map += HIR" ◇"HIW"weapon         "HIG"自铸兵器              "NOR;
 map += HIR" ◇"HIW"house          "HIG"自造房屋结婚生子      \n"NOR;
 map += HIR" ◇"HIW"transport      "HIG"交通工具              "NOR; 
 map += HIR" ◇"HIW"board          "HIG"留言板使用            \n"NOR; 
 map += HIR" ◇"HIW"biwu           "HIG"比武大会              "NOR;
 map += HIR" ◇"HIW"user_level     "HIG"玩家级别列表          \n"NOR;
 map += HIR" ◇"HIW"aboutquest     "HIG"任务说明              "NOR;
 map += HIR" ◇"HIW"wiz_apply      "HIG"巫师申请              \n"NOR;
 map += "  \n"NOR;
 map += HIY" 【命令介绍】\n"NOR;
 map += HIR" ◇"HIW"cmds           "HIG"常用指令              "NOR;
 map += HIR" ◇"HIW"channels       "HIG"交流和聊天频道        \n"NOR;
 map += HIR" ◇"HIW"cmd_system     "HIG"系统命令详析          "NOR;
 map += HIR" ◇"HIW"cmd_action     "HIG"冒险命令详析          \n"NOR;
 map += HIR" ◇"HIW"cmd_skill      "HIG"武功命令详析          "NOR;
 map += HIR" ◇"HIW"cmd_talk       "HIG"聊天命令详析          \n"NOR;
 map += HIR" ◇"HIW"cmd_special    "HIG"特殊命令详析          "NOR;
 map += HIR" ◇"HIW"commands       "HIG"命令汇总列表          \n"NOR;
 map += "  \n"NOR;
 map += HIY" 【武功介绍】\n"NOR;
 map += HIR" ◇"HIW"skill_apl      "HIG"武技运用详析          "NOR;
 map += HIR" ◇"HIW"force          "HIG"内功功用              \n"NOR; 
 map += HIR" ◇"HIW"skill_list     "HIG"武功绝招列表          "NOR;
 map += HIR" ◇"HIW"skill_comb     "HIG"武功互备列表          \n"NOR;
 map += HIR" ◇"HIW"skill_know     "HIG"知识技能列表          "NOR;
 map += "  \n\n"NOR;
 map += HIY" 【门派介绍】 \n"NOR;
 map += HIR" ◇"HIW"shaolin        "HIG"少林派介绍            "NOR;
 map += HIR" ◇"HIW"wudang         "HIG"武当派介绍            \n"NOR;
 map += HIR" ◇"HIW"emei           "HIG"峨嵋派介绍            "NOR;
 map += HIR" ◇"HIW"huashan        "HIG"华山派介绍            \n"NOR;
 map += HIR" ◇"HIW"gaibang        "HIG"丐帮介绍              "NOR;
 map += HIR" ◇"HIW"taohua         "HIG"桃花岛介绍            \n"NOR;
 map += HIR" ◇"HIW"xingxiu        "HIG"星宿派介绍            "NOR;
 map += HIR" ◇"HIW"baituo         "HIG"白驼山庄介绍          \n"NOR;
 map += HIR" ◇"HIW"shenlong       "HIG"神龙教介绍            "NOR;
 map += HIR" ◇"HIW"mizong         "HIG"密宗介绍              \n"NOR;  
 map += HIR" ◇"HIW"mingjiao       "HIG"明教介绍              "NOR;
 map += HIR" ◇"HIW"tiandihui      "HIG"天地会介绍            \n"NOR;
 map += HIR" ◇"HIW"dali           "HIG"大理介绍              "NOR;
 map += HIR" ◇"HIW"gumu           "HIG"古墓派介绍            \n"NOR;
 map += HIR" ◇"HIW"yipintang      "HIG"西夏一品堂介绍        "NOR;
 map += HIR" ◇"HIW"xiakedao       "HIG"侠客岛介绍            \n"NOR;  
 map += HIR" ◇"HIW"pixie-jian     "HIG"辟邪剑法介绍          "NOR;
 map += HIR" ◇"HIW"jinshe         "HIG"金蛇密芨介绍          \n"NOR;
 map += HIR" ◇"HIW"wuguan         "HIG"武馆介绍              "NOR;
 map += HIR" ◇"HIW"xiaoyao        "HIG"逍遥派介绍            \n"NOR;
map += HIR" ◇"HIW"lingjiu        "HIG"灵鹫介绍              "NOR;
map += HIR" ◇"HIW"quanzhen        "HIG"全真介绍              \n"NOR;
 map += "  \n"NOR;
 map += HIY" 【附属游戏介绍】 \n"NOR;
 map += HIR" ◇"HIW"pig_cmds       "HIG"拱猪的有关命令        "NOR;
 map += HIR" ◇"HIW"pig_rules      "HIG"拱猪规则              \n"NOR;
 map += HIR" ◇"HIW"bobing         "HIG"搏饼规则              "NOR;
 map += HIR" ◇"HIW"lottery        "HIG"彩票规则              \n"NOR;
 map += "\n"NOR;
 map += "                "HBBLU+HIW"请用 help <主题> 查看进一步的说明。 \n"NOR;


                me->start_more(map);
                return 1;
        }

        if( arg == "map_color" ) {
 map = "【“金庸群侠传”第一阶段总图】\n"NOR;
 map += NOR"                                                                  长白山\n"; 
 map += HIC"                                                              ≈"HIG"  "WHT"∧\n"NOR;
 map += NOR"                                                    赫图阿拉"HIY"－"HIC"≈"HIY"－"HIG"∧"CYN"¤\n";
 map += HIY"                                                       ｜     "HIC"≈  "HIG"∧"HIG"天池\n";  
 map += NOR"                                                      宁远  松花江\n";
 map += NOR"                           黑  "HIG"∧                     "HIY"／\n"NOR;
 map += NOR"                           木"HIW"@@@__"HIG" 平定州"HIY"－"HIG"北京   山海关       "HIB"≈≈\n";
 map += WHT"      ∧"HIG"                   崖"HIG"∧∧"HIY"／          ＼    ／         "HIB"≈≈\n";
 map += HIW"    @@@__             "HIG"灵州   "HIG"∧∧"HIG"    恒"HIW"@@_"HIG"∧"HIY" ／＼／         "HIB"≈≈≈\n";
 map += HIG"     ∧∧              "HIY"｜  ／"HIG"        山"HIG"∧∧∧   "HIY"｜         "HIB"≈≈"HIR"¤"HIG"神\n";
 map += NOR" 灵鹫峰"HIG"∧∧           "YEL"≈≈≈≈"HIG"黄河              "HIY"＋－"HIG"塘沽口"HIB"≈≈≈"HIG" 龙\n"; 
 map += HIY"         ＼"HIG" 星(天山)   "HIY"｜／＼             "HIG"∧"HIG"嵩"HIY"  ｜         "HIB"≈≈≈"HIG"岛\n";  
 map += HIY"          ＼"HIG"宿"HIG"∧∧"HIG"    永登  华         "HIW"@@_"HIG"∧"HIG"山"HIY"  ｜           "HIB"≈≈≈\n"NOR;
 map += NOR" 白驼       海 "HIG"∧∧"HIW"@@@__"HIG"    山         少"HIG"∧∧   "HIY"｜\n"; 
 map += WHT" ∧∧         "HIY"＼ "HIG"∧∧"HIG"       村"HIY"－"HIG"∧"HIG"     林"HIY"－－－"HIG"汝州               "HIB"≈≈≈\n";
 map += WHT"   ∧∧"HIY";;∷∷"HIG"   伊犁        "HIY"｜"HIW"@@@__"HIG"华  寺       "HIY"｜               "HIG"∧"HIG"泰  "HIB"≈≈≈\n"NOR;
 map += NOR"   大漠"HIY";;∷∷"HIG"戈壁  "HIY"＼       ＋ "HIG"∧∧"HIG"山          南阳    汉水   "HIW"@@@__"HIG"山   "HIB"≈≈≈\n";
 map += WHT"∧     "HIY";;∷∷∷∷－－＊       ＼       "HIG"∧"HIG" 中 "HIC"≈≈≈≈≈≈      "HIG"∧∧∧\n"; 
 map += HIG" ∧∧"WHT"∧∧   ∧"HIG"∧∧  "HIY"／ ＼  "HIG"古墓"HIY" ＼   "HIW"@@__"HIG" 条    "HIY"｜            ／       "HIB"≈≈≈\n";
 map += HIG"      ∧∧∧∧     "HIY"／   ＼  "HIG"终"HIG"∧"HIY"  ＼／"HIG"∧∧"HIG"山    "HIY"｜"GRN"±±"HIG"丐帮   "HIY"／\n"NOR;
 map += NOR"     昆仑山       "HIY"／     ＼ "HIG"南"HIG"∧"HIY"   ｜           ｜"GRN"±±"HIG"竹林  "HIY"／\n";
 map += HIY"                 ／"HIG"      嘉峪关"HIY"－－＋－－－－－"HIG"扬州"HIY"－－－－＊         "HIB"≈≈≈\n";
 map += WHT"    ∧     ∧"HIG"∧∧                               "HIY"｜"HIG"     燕   "HIY"＼       "HIB"≈≈≈\n";
 map += HIW"   @@@__"WHT"∧∧"HIG"∧∧                                "HIY"｜"HIG"     子 苏州"HIY"＋"HIG"嘉兴"HIB"≈≈"HIM"¤"HIB"≈\n";
 map += HIG"  ∧∧"HIG"大雪山             "HIY"＋－－－＋             ｜"HIG"     坞"HIY"－＋ ｜      "HIB"≈≈≈\n";
 map += HIG" ∧"HIY" ／                 ／＼        ＼           ｜"GRN"ψψ"HIY"        ｜"HIG"      桃花岛\n";
 map += HIG" ∧∧   ∧"HIG"青城        "HIY"／   ＼       ＋－－－－－＋"GRN"ψ"HIG"逍遥派    "HIY"＋－"HIG"杭州\n";
 map += HIG" ∧  "HIW"@@@___"HIY"－＋      ／      ＼                 ｜"GRN"ψψ"HIG"树林    "HIY"｜\n";
 map += HIR"血"HIG"∧   ∧∧  "HIY"｜     ／    "HIG"∧"HIG" 武"HIY"＼                ＼           ｜\n";
 map += HIR"刀"HIG" ∧"HIY"＼"HIG"     成都"HIY"－＋   "HIW"@@@_"HIG"∧"HIG"当 "HIY"｜                ＼"HIG"    武 "HIG"∧"HIY" ｜\n";
 map += HIY"       －－－＋   ｜    "HIG"∧∧∧∧"HIY"｜       "HIG"∧"HIG" 衡    "HIY"／＼"HIG"  夷"HIG"∧∧"HIY"｜    "HIB"≈≈≈\n"NOR;
 map += HIY"                  ｜            ｜    "HIW"@@__"HIG"∧"HIG"山   "HIY"／  ＼"HIG"      延平\n";
 map += HIG"         ∧∧    "HIY"／"HIG"       摩"HIG"∧  "HIY"｜     "HIG"∧∧∧   "HIY"／    ＼     ／＼\n";
 map += HIW"       @@@__"HIG"∧"HIY" ＊"HIG"         天"HIG"∧"HIY"－＋－－－－"HIG"衡阳"HIY"＋        ＋－＋"HIG"  福州   "HIB"≈≈≈\n";
 map += NOR"     峨嵋"HIG"∧"HIW"@_"HIG"∧"HIY"｜"HIG"         崖    "HIY"｜                               ｜   "HIB"≈≈≈\n"NOR;
 map += HIY"               ｜               ｜                              "HIG"泉州"HIB"≈≈"HIG"澎湖\n";
 map += NOR"      万劫谷"HIY"＼／                ｜                            ／     "HIB"≈"HIG"¤"HIB"≈≈\n";
 map += NOR"             "HIY"｜ "HIC"≈≈"HIG"滇"HIY"          ｜                          ／     "HIB"≈≈≈"HIG"¤"HIB"≈\n";
 map += HIG"         ∧"HIG" 大理"HIC"≈≈"HIG"池"HIY"          ｜                        ／        "HIB"≈≈"HIG"台湾"HIB"≈\n";
 map += NOR"     苍山"HIG"∧"HIY"  ＋－－－－－－－－"HIG"佛山"HIY"－－－－－－－－－－－＋"HIB"   ≈≈≈≈≈≈ \n";
 map += HIY"                                ｜                "HIB"≈≈≈≈≈≈≈\n";
 map += HIB"                  ≈≈     "HIB"≈≈"HIG"渔港"HIB"≈≈≈      ≈≈  ≈≈   \n";
 map += HIB"            ≈≈≈≈≈≈≈≈≈        ≈≈ ≈≈ ≈≈\n";
 map += HIB"                ≈≈≈≈≈≈    ≈≈   ≈≈  ≈≈\n";
 map += HIB"                          ≈≈≈"HIY"¤"HIG"侠客岛"HIB"≈≈\n";
 map += HIB"                             ≈≈≈≈≈≈≈\n";
 map += "\n";
 map += NOR"                                             Modified by wind 3.1 1999\n";
 
        me->start_more(map);
                return 1;
        }

        // Else, try if a command name is specified.
        seteuid(getuid());
        if( stringp(file = me->find_command(arg)) ) {
                notify_fail("有这个指令存在，但是并没有详细的说明文件。\n");
                return file->help(me);
        }

        // Search the individual search path first.
        if( pointerp(search = me->query("help_search_path")) ) {
                i = sizeof(search);
                while(i--) if( file_size(search[i] + arg)>0 ) {
                        me->start_more( read_file(search[i] + arg) );
                        return 1;
                }
        }

        // Support efun/lfun help with same name as other topics such as
        // ed() and ed command.
        sscanf(arg, "%s()", arg);

        // Finally, search the default search paths.
        if( pointerp(default_search) ) {
                i = sizeof(default_search);
                while(i--) if( file_size(default_search[i] + arg)>0 ) {
                        me->start_more( read_file(default_search[i] + arg) );
                        return 1;
                }
        }
        
        // modify byp@jyqxz 
        if(wizardp(me) && pointerp(wizard_search)) {
                i = sizeof(wizard_search);
                while(i--) if( file_size(wizard_search[i] + arg)>0 ) {
                        me->start_more( read_file(wizard_search[i] + arg) );
                        return 1;
                }
        }
        return notify_fail("没有针对这项主题的说明文件。\n");
}

int help(object me)
{
        write(@HELP
指令格式：help <主题>              

这个指令提供你针对某一主题的详细说明文件，若是不指定主题，则提供你有关
主题的文件。
HELP
        );
        return 1;
}
