// Room: /d/taohuacun/taohua3.c

inherit ROOM;

string look_shibei();
void create()
{
	set("short", "�һ���");
	set("long", @LONG
˳Ϫ�����ϣ�����ɽ�ƽ��ߣ���ˮ����������Ҳ�����ܼ�����
���һ�ӵ�ܳ�һƬ��ϼ�����Ĵ���ʱʱ�ɼ���Ȫ���٣������¼䡣
�һ�Ϫˮ������������۳���������Ϸ����������һ����ˡ��ȿ�
һ������ߵ�С׭ʯ��(shibei)б��·�ԡ�
LONG );
	set("outdoors", "city");
	set("no_clean_up", 0);
	set("item_desc", ([
		"shibei" : (: look_shibei :),
	]));
	set("exits", ([
		"eastdown" : __DIR__"taohua2",
		"northup"  : __DIR__"taohua4",
	]));
	setup();
//	replace_program(ROOM);
}

string look_shibei()
{
        return
        "������������������������������\n"
        "����                      ����\n"
        "����        �һ���        ����\n"
        "����                      ����\n"
        "������������������������������\n";
}
