// Room: /guiyun/duchuan.c
// Date: Nov.18 1998 by Winder

inherit ROOM;

void create()
{
	set("short", "�ɴ�");
	set("long", @LONG
�밶��Զ����������������Ī֪���֮�ں������ֻ��Ǻ���֮
����ء����ҹ��ڴ�β���еػ���ˮ��
LONG );
        set("outdoors", "city");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
