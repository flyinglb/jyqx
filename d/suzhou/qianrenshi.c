// Room: /d/suzhou/qianrenshi.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "ǧ��ʯ");
	set("long", @LONG
�ڻ���ɽ���ģ���һ��ǧ��ʯ����ʯ�ʰ��Ϻ�ɫ��������
����бʯ����ƽ̹��ʯ���縫������˵����Ĺ���ɺ����ӷ�
����й¶��Ĺ���ܼٽ�Ĺ��ף�ƹ���֮������ǧ��������ȫ��
ɱ¾����Ѫ��͸ʯ�У��ɰ���ɫ��
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"      : __DIR__"erxianting",
		"north"     : __DIR__"shijianshi",
		"northwest" : __DIR__"zhishuang",
	]));
	setup();
	replace_program(ROOM);
}

