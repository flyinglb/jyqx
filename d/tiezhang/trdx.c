// room: dong-2.c
// zqb


inherit ROOM;
#include <ansi.h>
string look_bei();
void create()
{
        set("short", HIR"天然洞穴"NOR);
        set("long", @LONG
    这石洞系天然生成，较之外面人工开凿的石室大了十来倍。放眼望
去，洞内共有十余具骸骨，或做或卧，神态各有不同，有的骸骨散开在地，
有的却仍具完好人形，更有些骨坛灵位之属。每具骸骨之旁都放着兵刃，暗
器，用具，珍宝等物。洞口处立着一座石碑(bei)。
LONG
        );
        set("exits", ([
            "out" : __DIR__"dong-3",
        ]));
        set("item_desc",([
        "bei"         :       (: look_bei :),
    ]));

        set("objects", ([
           
        __DIR__"obj/haigu2" : 1,  
        __DIR__"obj/ycj" : 1,      
        ]));

        set("no_clean_up", 0);

        setup();
        //replace_program(ROOM);
}
string look_bei()
{
        return
        "\n"
"    �   擅动室内物品者\n"    
        "\n"
RED"        死伤莫怪！    \n"NOR
        "\n";
}

