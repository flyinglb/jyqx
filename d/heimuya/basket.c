// Room: /d/heimuya/basket.c

inherit ROOM;
void create()
{
	set("short", "��¨");
	set("long", @LONG
����һֻ����¨�����װ��ʮ��ʯ�ס�̧ͷ������ֻ��ͷ��
������±ڣ����ľ����ʵ�ߵ�������
LONG );
	set("outdoors", "heimuya");
        set("no_fight", 1);
        set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
