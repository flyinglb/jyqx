// Room: /d/fuzhou/wushan.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "������ɽ");
	set("long", @LONG
��ɽ��ս��ʱ��Խ���ڴ˾�ס���������ഫ��Խ������
���ھ��¾��մ����ڴˣ��ֳơ�����ɽ������ɽ֮´�İ�����
�ֳƶ�������ϵ������֪Ϊ������ȥ�ĸ�ĸ��������������
�����ų������续��
LONG );
	set("exits", ([
                "northdown" : __DIR__"dongdajie",
	]));
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

