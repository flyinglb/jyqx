// academy.c
//by byp@MX 2000/06/20

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIW"��ʦѧԺ"NOR);
        set("long", 
"��������ʦ���о� LPC �ĵط������й��ڳ�������ⶼ�������������
���м��и�ټ������(shujia)��������˺ܶ���� LPC ���Ժ� MX ���ܡ�
����������顣�Ա��п�ʯ��(shiban)���������ѧԺ�ľ���
"
        );

        set("no_fight", 1);
        set("no_steal", 1); 
        set("no_sleep_room", 1); 
        set("outdoors", "wizard"); 
        set("valid_startroom",1);
        
        set("item_desc", ([
                "shiban" : "\n    "HIR"�� �� �� �� ��\n    �� �� �� �� ��"NOR"\n\n",
                "shujia" : "    �ȴ�����׫д ���� \n\n",
        ]));
        
        set("exits", ([ /* sizeof() == 1 */
                "south" : __DIR__"wizard_room",
        ]));

        setup();
        "/clone/board/wiz_academy_b"->foo();
}
