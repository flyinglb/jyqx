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
 map = "                "HBBLU+HIW"�I����ӹȺ�����������ļ� �I (2000.09.12.��) \n"NOR;
 map += "\n"NOR;
 map += HIY" ����Ϸ�ſ���\n"NOR;
 map += HIR" ��"HIW"intro          "HIG"����ӹȺ���������    "NOR;
 map += HIR" ��"HIW"maps           "HIG"����ӹȺ��������ͼ��  \n"NOR;
 map += HIR" ��"HIW"newbie         "HIG"����ӹȺ����������ָ��"NOR;
 map += HIR" ��"HIW"news           "HIG"����ӹȺ��������������\n"NOR;
 map += HIR" ��"HIW"rules          "HIG"����ӹȺ��������ҹ���"NOR;
 map += HIR" ��"HIW"wiz_rules      "HIG"����ӹȺ��������ʦ����\n"NOR;
 map += HIR" ��"HIW"settings       "HIG"������������          "NOR;
 map += HIR" ��"HIW"gift_char      "HIG"�츳���Թ�ϵͼ        \n"NOR;
 map += HIR" ��"HIW"weapon         "HIG"��������              "NOR;
 map += HIR" ��"HIW"house          "HIG"���췿�ݽ������      \n"NOR;
 map += HIR" ��"HIW"transport      "HIG"��ͨ����              "NOR; 
 map += HIR" ��"HIW"board          "HIG"���԰�ʹ��            \n"NOR; 
 map += HIR" ��"HIW"biwu           "HIG"������              "NOR;
 map += HIR" ��"HIW"user_level     "HIG"��Ҽ����б�          \n"NOR;
 map += HIR" ��"HIW"aboutquest     "HIG"����˵��              "NOR;
 map += HIR" ��"HIW"wiz_apply      "HIG"��ʦ����              \n"NOR;
 map += "  \n"NOR;
 map += HIY" ��������ܡ�\n"NOR;
 map += HIR" ��"HIW"cmds           "HIG"����ָ��              "NOR;
 map += HIR" ��"HIW"channels       "HIG"����������Ƶ��        \n"NOR;
 map += HIR" ��"HIW"cmd_system     "HIG"ϵͳ��������          "NOR;
 map += HIR" ��"HIW"cmd_action     "HIG"ð����������          \n"NOR;
 map += HIR" ��"HIW"cmd_skill      "HIG"�书��������          "NOR;
 map += HIR" ��"HIW"cmd_talk       "HIG"������������          \n"NOR;
 map += HIR" ��"HIW"cmd_special    "HIG"������������          "NOR;
 map += HIR" ��"HIW"commands       "HIG"��������б�          \n"NOR;
 map += "  \n"NOR;
 map += HIY" ���书���ܡ�\n"NOR;
 map += HIR" ��"HIW"skill_apl      "HIG"�似��������          "NOR;
 map += HIR" ��"HIW"force          "HIG"�ڹ�����              \n"NOR; 
 map += HIR" ��"HIW"skill_list     "HIG"�书�����б�          "NOR;
 map += HIR" ��"HIW"skill_comb     "HIG"�书�����б�          \n"NOR;
 map += HIR" ��"HIW"skill_know     "HIG"֪ʶ�����б�          "NOR;
 map += "  \n\n"NOR;
 map += HIY" �����ɽ��ܡ� \n"NOR;
 map += HIR" ��"HIW"shaolin        "HIG"�����ɽ���            "NOR;
 map += HIR" ��"HIW"wudang         "HIG"�䵱�ɽ���            \n"NOR;
 map += HIR" ��"HIW"emei           "HIG"�����ɽ���            "NOR;
 map += HIR" ��"HIW"huashan        "HIG"��ɽ�ɽ���            \n"NOR;
 map += HIR" ��"HIW"gaibang        "HIG"ؤ�����              "NOR;
 map += HIR" ��"HIW"taohua         "HIG"�һ�������            \n"NOR;
 map += HIR" ��"HIW"xingxiu        "HIG"�����ɽ���            "NOR;
 map += HIR" ��"HIW"baituo         "HIG"����ɽׯ����          \n"NOR;
 map += HIR" ��"HIW"shenlong       "HIG"�����̽���            "NOR;
 map += HIR" ��"HIW"mizong         "HIG"���ڽ���              \n"NOR;  
 map += HIR" ��"HIW"mingjiao       "HIG"���̽���              "NOR;
 map += HIR" ��"HIW"tiandihui      "HIG"��ػ����            \n"NOR;
 map += HIR" ��"HIW"dali           "HIG"�������              "NOR;
 map += HIR" ��"HIW"gumu           "HIG"��Ĺ�ɽ���            \n"NOR;
 map += HIR" ��"HIW"yipintang      "HIG"����һƷ�ý���        "NOR;
 map += HIR" ��"HIW"xiakedao       "HIG"���͵�����            \n"NOR;  
 map += HIR" ��"HIW"pixie-jian     "HIG"��а��������          "NOR;
 map += HIR" ��"HIW"jinshe         "HIG"������ܸ����          \n"NOR;
 map += HIR" ��"HIW"wuguan         "HIG"��ݽ���              "NOR;
 map += HIR" ��"HIW"xiaoyao        "HIG"��ң�ɽ���            \n"NOR;
map += HIR" ��"HIW"lingjiu        "HIG"���ս���              "NOR;
map += HIR" ��"HIW"quanzhen        "HIG"ȫ�����              \n"NOR;
 map += "  \n"NOR;
 map += HIY" ��������Ϸ���ܡ� \n"NOR;
 map += HIR" ��"HIW"pig_cmds       "HIG"������й�����        "NOR;
 map += HIR" ��"HIW"pig_rules      "HIG"�������              \n"NOR;
 map += HIR" ��"HIW"bobing         "HIG"��������              "NOR;
 map += HIR" ��"HIW"lottery        "HIG"��Ʊ����              \n"NOR;
 map += "\n"NOR;
 map += "                "HBBLU+HIW"���� help <����> �鿴��һ����˵���� \n"NOR;


                me->start_more(map);
                return 1;
        }

        if( arg == "map_color" ) {
 map = "������ӹȺ��������һ�׶���ͼ��\n"NOR;
 map += NOR"                                                                  ����ɽ\n"; 
 map += HIC"                                                              ��"HIG"  "WHT"��\n"NOR;
 map += NOR"                                                    ��ͼ����"HIY"��"HIC"��"HIY"��"HIG"��"CYN"��\n";
 map += HIY"                                                       ��     "HIC"��  "HIG"��"HIG"���\n";  
 map += NOR"                                                      ��Զ  �ɻ���\n";
 map += NOR"                           ��  "HIG"��                     "HIY"��\n"NOR;
 map += NOR"                           ľ"HIW"@@@__"HIG" ƽ����"HIY"��"HIG"����   ɽ����       "HIB"�֡�\n";
 map += WHT"      ��"HIG"                   ��"HIG"�ġ�"HIY"��          ��    ��         "HIB"�֡�\n";
 map += HIW"    @@@__             "HIG"����   "HIG"�ġ�"HIG"    ��"HIW"@@_"HIG"��"HIY" ���ܣ�         "HIB"�֡֡�\n";
 map += HIG"     �ġ�              "HIY"��  ��"HIG"        ɽ"HIG"�ġġ�   "HIY"��         "HIB"�֡�"HIR"��"HIG"��\n";
 map += NOR" ���շ�"HIG"�ġ�           "YEL"�֡֡֡�"HIG"�ƺ�              "HIY"����"HIG"������"HIB"�֡֡�"HIG" ��\n"; 
 map += HIY"         ��"HIG" ��(��ɽ)   "HIY"������             "HIG"��"HIG"��"HIY"  ��         "HIB"�֡֡�"HIG"��\n";  
 map += HIY"          ��"HIG"��"HIG"�ġ�"HIG"    ����  ��         "HIW"@@_"HIG"��"HIG"ɽ"HIY"  ��           "HIB"�֡֡�\n"NOR;
 map += NOR" ����       �� "HIG"�ġ�"HIW"@@@__"HIG"    ɽ         ��"HIG"�ġ�   "HIY"��\n"; 
 map += WHT" �ġ�         "HIY"�� "HIG"�ġ�"HIG"       ��"HIY"��"HIG"��"HIG"     ��"HIY"������"HIG"����               "HIB"�֡֡�\n";
 map += WHT"   �ġ�"HIY";;�ˡ�"HIG"   ����        "HIY"��"HIW"@@@__"HIG"��  ��       "HIY"��               "HIG"��"HIG"̩  "HIB"�֡֡�\n"NOR;
 map += NOR"   ��Į"HIY";;�ˡ�"HIG"���  "HIY"��       �� "HIG"�ġ�"HIG"ɽ          ����    ��ˮ   "HIW"@@@__"HIG"ɽ   "HIB"�֡֡�\n";
 map += WHT"��     "HIY";;�ˡˡˡˣ�����       ��       "HIG"��"HIG" �� "HIC"�֡֡֡֡֡�      "HIG"�ġġ�\n"; 
 map += HIG" �ġ�"WHT"�ġ�   ��"HIG"�ġ�  "HIY"�� ��  "HIG"��Ĺ"HIY" ��   "HIW"@@__"HIG" ��    "HIY"��            ��       "HIB"�֡֡�\n";
 map += HIG"      �ġġġ�     "HIY"��   ��  "HIG"��"HIG"��"HIY"  �ܣ�"HIG"�ġ�"HIG"ɽ    "HIY"��"GRN"����"HIG"ؤ��   "HIY"��\n"NOR;
 map += NOR"     ����ɽ       "HIY"��     �� "HIG"��"HIG"��"HIY"   ��           ��"GRN"����"HIG"����  "HIY"��\n";
 map += HIY"                 ��"HIG"      ������"HIY"����������������"HIG"����"HIY"����������         "HIB"�֡֡�\n";
 map += WHT"    ��     ��"HIG"�ġ�                               "HIY"��"HIG"     ��   "HIY"��       "HIB"�֡֡�\n";
 map += HIW"   @@@__"WHT"�ġ�"HIG"�ġ�                                "HIY"��"HIG"     �� ����"HIY"��"HIG"����"HIB"�֡�"HIM"��"HIB"��\n";
 map += HIG"  �ġ�"HIG"��ѩɽ             "HIY"����������             ��"HIG"     ��"HIY"���� ��      "HIB"�֡֡�\n";
 map += HIG" ��"HIY" ��                 ����        ��           ��"GRN"�צ�"HIY"        ��"HIG"      �һ���\n";
 map += HIG" �ġ�   ��"HIG"���        "HIY"��   ��       ��������������"GRN"��"HIG"��ң��    "HIY"����"HIG"����\n";
 map += HIG" ��  "HIW"@@@___"HIY"����      ��      ��                 ��"GRN"�צ�"HIG"����    "HIY"��\n";
 map += HIR"Ѫ"HIG"��   �ġ�  "HIY"��     ��    "HIG"��"HIG" ��"HIY"��                ��           ��\n";
 map += HIR"��"HIG" ��"HIY"��"HIG"     �ɶ�"HIY"����   "HIW"@@@_"HIG"��"HIG"�� "HIY"��                ��"HIG"    �� "HIG"��"HIY" ��\n";
 map += HIY"       ��������   ��    "HIG"�ġġġ�"HIY"��       "HIG"��"HIG" ��    "HIY"����"HIG"  ��"HIG"�ġ�"HIY"��    "HIB"�֡֡�\n"NOR;
 map += HIY"                  ��            ��    "HIW"@@__"HIG"��"HIG"ɽ   "HIY"��  ��"HIG"      ��ƽ\n";
 map += HIG"         �ġ�    "HIY"��"HIG"       Ħ"HIG"��  "HIY"��     "HIG"�ġġ�   "HIY"��    ��     ����\n";
 map += HIW"       @@@__"HIG"��"HIY" ��"HIG"         ��"HIG"��"HIY"������������"HIG"����"HIY"��        ������"HIG"  ����   "HIB"�֡֡�\n";
 map += NOR"     ����"HIG"��"HIW"@_"HIG"��"HIY"��"HIG"         ��    "HIY"��                               ��   "HIB"�֡֡�\n"NOR;
 map += HIY"               ��               ��                              "HIG"Ȫ��"HIB"�֡�"HIG"���\n";
 map += NOR"      ��ٹ�"HIY"�ܣ�                ��                            ��     "HIB"��"HIG"��"HIB"�֡�\n";
 map += NOR"             "HIY"�� "HIC"�֡�"HIG"��"HIY"          ��                          ��     "HIB"�֡֡�"HIG"��"HIB"��\n";
 map += HIG"         ��"HIG" ����"HIC"�֡�"HIG"��"HIY"          ��                        ��        "HIB"�֡�"HIG"̨��"HIB"��\n";
 map += NOR"     ��ɽ"HIG"��"HIY"  ������������������"HIG"��ɽ"HIY"������������������������"HIB"   �֡֡֡֡֡� \n";
 map += HIY"                                ��                "HIB"�֡֡֡֡֡֡�\n";
 map += HIB"                  �֡�     "HIB"�֡�"HIG"���"HIB"�֡֡�      �֡�  �֡�   \n";
 map += HIB"            �֡֡֡֡֡֡֡֡�        �֡� �֡� �֡�\n";
 map += HIB"                �֡֡֡֡֡�    �֡�   �֡�  �֡�\n";
 map += HIB"                          �֡֡�"HIY"��"HIG"���͵�"HIB"�֡�\n";
 map += HIB"                             �֡֡֡֡֡֡�\n";
 map += "\n";
 map += NOR"                                             Modified by wind 3.1 1999\n";
 
        me->start_more(map);
                return 1;
        }

        // Else, try if a command name is specified.
        seteuid(getuid());
        if( stringp(file = me->find_command(arg)) ) {
                notify_fail("�����ָ����ڣ����ǲ�û����ϸ��˵���ļ���\n");
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
        return notify_fail("û��������������˵���ļ���\n");
}

int help(object me)
{
        write(@HELP
ָ���ʽ��help <����>              

���ָ���ṩ�����ĳһ�������ϸ˵���ļ������ǲ�ָ�����⣬���ṩ���й�
������ļ���
HELP
        );
        return 1;
}
