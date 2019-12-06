// academy.c
//by byp@MX 2000/06/20

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIW"巫师学院"NOR);
        set("long", 
"这里是巫师们研究 LPC 的地方，所有关于程序的问题都可以在这里提出
。中间有个偌大的书架(shujia)，里面放了很多关于 LPC 语言和 MX 构架、
函数定义的书。旁边有块石板(shiban)，上面刻着学院的精神。
"
        );

        set("no_fight", 1);
        set("no_steal", 1); 
        set("no_sleep_room", 1); 
        set("outdoors", "wizard"); 
        set("valid_startroom",1);
        
        set("item_desc", ([
                "shiban" : "\n    "HIR"不 耻 下 问 ！\n    百 问 不 厌 ！"NOR"\n\n",
                "shujia" : "    等待您的撰写 …… \n\n",
        ]));
        
        set("exits", ([ /* sizeof() == 1 */
                "south" : __DIR__"wizard_room",
        ]));

        setup();
        "/clone/board/wiz_academy_b"->foo();
}
