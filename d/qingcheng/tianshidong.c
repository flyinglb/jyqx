// Room: /qingcheng/tianshidong.c
// Date: Frb.20 1998 by Java

inherit ROOM;
void create()
{
	set("short", "��ʦ��");
	set("long", @LONG
��ʦ���Զ��������ڴ˽��������������������ų����ۡ�����
ɽ����Ԫ�����ͱڼ䡣������ʦ�����ұ����ȿ�ͨ������������
����ܻ��ȣ��۾��̨�����ƺ�ΰ���ڹ����ˡ���ũ����ԯ����
ʯ������
LONG );
	set("exits", ([
		"northup"  : __DIR__"gulongqiao",
		"north"    : __DIR__"sanqingdian",
		"eastdown" : __DIR__"path2",
		"west"     : __DIR__"yinxing",
		"east"     : __DIR__"sandaoshi",
	]));
        set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

