// Room: /d/gaochang/room63.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "����ɽ");
	set("long", @LONG
��һ����ľ������ɽʯ��ᾣ��������ǲ��㣬ɽ�ϻ�ѩ���񣬵�·��᫣���
�����Ƿ�����ת������ɽ�£�����һ�������֡��������������������������֦
�½��ᣬһ�����֣�����ɽ����¡�����ɽ�壬��ʱ���ۣ��������Ķ��ǡ�
LONG
	);
	set("no_new_clean_up", 0);
	set("outdoors", "room63");
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"room62",
        "east" : "/d/kunlun/shalu",
        "west" : "/d/npc/m_weapon/lianfushi",
]));

	setup();
	replace_program(ROOM);
}
