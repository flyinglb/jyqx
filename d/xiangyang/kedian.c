// Room: /d/xiangyang/kedian.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "������ջ");
	set("long", @LONG
����һ�ҶԽ�����ʿ��˵���������Ŀ�ջ�����ǵ�������
һ�㶼ס�����һ�Ǳ��ˣ��������������ϵ�������顣��
�����������˵���ʮ�Σ��������������Ǿ����������Ǵ����
�����˳��ݷ�һ�¹���������֮ʿ��
LONG );
        set("no_sleep_room",1);
	set("no_clean_up", 0);
	set("no_fight", 1);
	set("valid_startroom", 1);

	set("exits", ([
		"east" : __DIR__"westroad1",
	]));
	set("objects", ([
		__DIR__"npc/wudunru" : 1,
	]));
	setup();
	replace_program(ROOM);
	"/clone/board/kedian6_b"->foo();
}
