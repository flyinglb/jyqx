#include <ansi.h>

inherit ROOM;
string look_bian();

void create()
{
        set("short", "����");
        set("long", @LONG
��ǰ��һ��ׯԺ����¥�����ߴ���ש���ߣ����ɫ��
��(bian)��д�š���ָɽׯ���ĸ�����֡���������������
��ׯ���ױ�����֣�Ϊ��ָɽׯ��ɫ���١�
LONG    );
        set("item_desc", ([ 
        "bian"       :       (: look_bian :),
]));
        set("exits", ([ 
  "enter" : __DIR__"qianyuan",
  "out" :"/d/village/ehouse2",

]));

//        set("no_clean_up", 0);

        setup();
        
}
string look_bian()
{
    return
               HIC"          ####################################\n"
                  "          ####                            ####\n"
                  "          ####    ��    ָ    ɽ    ׯ    ####\n"  
                  "          ####                            ####\n"
                  "          ####################################\n"NOR;
}

