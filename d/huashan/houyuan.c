//houyuan.c
inherit ROOM;
void create()
{
	set("short","��Ժ");
	set("long",@LONG
�����ǻ�ɽ�ɵĺ�Ժ�������ǻ�ɽ���ӵľ��Һ�����������ɽ������
��ɽ�����������վ��������������¡���������һ��С��Ժ���м�ɽС�أ�
��ɫ���ˣ����н�����԰����ɫ��
LONG);
	set("exits",([
		"northeast"  : __DIR__"garden",
		"west"       : __DIR__"jiashan",
		"east"       : __DIR__"xuanya",
	]));
	set("outdoors", "xx");
        set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
 
