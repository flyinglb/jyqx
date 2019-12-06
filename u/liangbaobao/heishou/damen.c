#include <ansi.h>

inherit ROOM;
string look_bian();

void create()
{
        set("short", "大门");
        set("long", @LONG
面前是一座庄院，门楼不甚高大，青砖绿瓦，金黄色的
匾(bian)上写着『五指山庄』四个大黑字。牌匾是新做的是
请庄主亲笔提的字，为五指山庄争色不少。

LONG    );
        set("item_desc", ([ 
        "bian"       :       (: look_bian :),
]));
        set("exits", ([ 
  "enter" : __DIR__"qianyuan",
  "out" :"/d/huanghe/caodi1",

]));

//        set("no_clean_up", 0);

        setup();
        
}
string look_bian()
{
    return
    "\n"
               HIY"          ####################################\n"
                  "          ####                            ####\n"
                  "          ####    五    指    山    庄    ####\n"  
                  "          ####                            ####\n"
                  "          ####################################\n"NOR;
    "\n";
}

