//garden.c
inherit ROOM;
void create()
{
	set("short","��԰");
	set("long",@LONG
����һ��԰�ӣ�ͥԺ���ģ����ֻ������ǲ��١��ٻ����ţ�ɽʯ��׾��
�������壬���ɴ��񣬾���ɷ�����ˡ��峺��Ϫ����������һ��Сͤ�ӣ�
����Ϫˮ��������ȥ������ͨ��������Ϊ����������һ�����ȣ�����С��
����������ζ������������ȥ������
LONG);
	set("exits",([
		"east"      : __DIR__"buwei1",
		"west"      : __DIR__"chufang",
		"north"     : __DIR__"changlang",
		"south"     : __DIR__"shufang",
		"southwest" : __DIR__"houyuan",
	]));
	set("outdoors", "xx");
        set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
 
