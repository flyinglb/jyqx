// Room: /d/xiangyang/guofushufang.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�鷿");
	set("long", @LONG
���ǹ������鷿���ұ�����ܣ���������ŵ��Һ���ҵ�
һЩ�伮��ȴû��һ������ѧ�йص��顣��߿����ĵط�����
һ��ľ����������ű�īֽ�⣬���Ϸ��ż����飬�ڷŵ�����
���룬���õ�һ����Ⱦ�����ﵽ������ɨ��һ����Ⱦ��������
�������Կ�������������ӳ��ʱ��΢���뻧���ź����ϻ�ȼ��
һ¯̴�㣬�뵵����������ɢ��ʹ���������������ȫƽ
��������
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"guofuhuayuan",
	]));
	setup();
	replace_program(ROOM);
}

