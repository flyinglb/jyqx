// Room: /u/zqb/tiezhang/shanlu-7.c
#include <ansi.h>

inherit ROOM;

string look_dazi();

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
    ������һ����᫵�ɽ·�ϣ�����ɽ����������ݹ������м�һ��
��С·������һ����ǿ��ȥ��ǰ����һƬï�ܵ����֡�·�Ե�ʯ���Ͽ�
�ż�������(dazi)��
LONG	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"sslin-1",
  "southdown" : __DIR__"shanlu-6",
]));

    set("item_desc",([
        "dazi"         :       (: look_dazi :),
    ]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");

	setup();
}

string look_dazi()
{
        return
        "\n"
"    ���ư��ص�    \n"    
        "\n"
 "    ������----    \n"
RED"              ����    \n"NOR
        "\n";
}

