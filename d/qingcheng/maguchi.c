// Room: /qingcheng/maguchi.c
// Date: Frb.20 1998 by Java

inherit ROOM;
void create()
{
	set("short", "��ó�");
	set("long", @LONG
�����������óأ������ء��������ߣ�������£�ˮɫ��
�����ļ����겻ӯ���������ԡ�
LONG );
        set("outdoors","qingcheng");
        set("resource/water", 1);
	set("exits", ([
		"west"     : __DIR__"shangqing",
	]));
        set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

