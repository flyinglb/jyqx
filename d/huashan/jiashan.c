// jiashan.c
inherit ROOM;
void create()
{
	set("short","��ɽС��");
	set("long",@LONG
������һ��С԰�ӣ���ͷ�и�С���������ܲ��м�ɽ��������԰������
����ʱ��ˮ����Ϫ���У�����ˮ���������������̰��ö���ˮ��������
̧ͷ������ֻ��Զ����ɽ���죬�������֣��꾰��Ȥ���
LONG);
	set("exits",([
		"east" : __DIR__"houyuan",
	]));
	set("outdoors", "xx");
        set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
 
