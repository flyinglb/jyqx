// Room: /qingcheng/sandaoshi.c
// Date: Frb.20 1998 by Java

inherit ROOM;
void create()
{
	set("short", "����ʯ");
	set("long", @LONG
����ʯ�Ͽ̡���ħ�����֣��ഫΪ����ʦ���꽵ħ�����ʯ��
�����ӽ�������ʯ��Ϊ������Ϊ���������ĵ�ʯ��ʯ�Ѵ���Ȼ����
ʯ�ݡ�
LONG );
        set("outdoors","qingcheng");
	set("exits", ([
		"west"     : __DIR__"tianshidong",
		"eastdown" : __DIR__"tingquanting",
	]));
        set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

