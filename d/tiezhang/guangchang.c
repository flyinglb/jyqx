// Room: /u/zqb/tiezhang/guangchang.c

inherit ROOM;

void create()
{
	set("short", "�㳡");
	set("long", @LONG
    ɽ·�е������Ȼ��ÿ���������ǰ������һƬ�ܴ�Ĺ㳡��һ
Щ���ư�ĵ������ش�������䣬�Եú�æµ���ڹ㳡����Χ�кܶ���ʯ��
�ķ��ӡ��������������Եøߴ���ΰ������ķ����в�ʱ��ӿ����������
����仹�����Źķ��������
LONG	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"shanlu-2.c",
  "west" : __DIR__"lgfang",
  "east" : __DIR__"guajia",
  "northup" : __DIR__"wztang",
]));
    set("objects", ([ /* sizeof() == 3 */
    __DIR__"npc/huiyi" : 2,
    __DIR__"npc/heiyi" : 2,
//    "/d/biwu/champion_tz":1,
    __DIR__"obj/axe" : 1,
    ]));
    set("valid_startroom", 1);
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");

	setup();
    "/clone/board/tiezhang_b"->foo();
	replace_program(ROOM);
//    "/clone/board/tiezhang_b"->foo();
}

