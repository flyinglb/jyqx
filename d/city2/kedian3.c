
inherit ROOM;

void create()
{
	set("short", "���ͷ�");
	set("long", @LONG
һ���ţ�ֻ�����������ֳֽ䵶��Χ��һ����Ů��ƴ����ɱ��
ֻ�Ǹ�����Ů��������Ʒ��ס�ˣ��۲��������ǰ���Ů��ͷ��
��ð��˿˿��������Ȼ�Ѿ���ȫ������ֻһ���۰���֧����ȥ��
�����ԵֵС����ϰ߰ߵ�㶼��Ѫ����
LONG );
	set("exits", ([
		"west" : __DIR__"kedian2",
	]));
	set("objects", ([
		"/d/city2/npc/dubi":1,
		"/d/city2/npc/lama":6,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}



