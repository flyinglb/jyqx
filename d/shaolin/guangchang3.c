// Room: /d/shaolin/guangchang3.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "���޳�");
	set("long", @LONG
���ǽ���Ժǰ�����޳���������ȫ�½�ͨ���ܼ��ĵط���ֻ
��һ�Ӷ�ɮ������ȥȥ�����Ÿ��ַ�ɫ���е�Я������ǹ������
�ȵȱ������������˽ý�����̬ׯ�ء�����Ĵ����ǽ���Ժ��
��λɮ���ֵ��������ࡣ����ͨ��ի����
LONG );
	set("exits", ([
		"south" : __DIR__"guangchang2",
		"north" : __DIR__"guangchang4",
		"northup" : __DIR__"jlyuan",
		"west" : __DIR__"fanting",
	]));
	set("no_clean_up", 0);
	set("outdoors", "shaolin");
	setup();
}

int valid_leave(object me, string dir)
{
	mapping fam;

	if (dir == "northup")
	{
		if( mapp(fam = me->query("family")) 
		&&  fam["family_name"] == "������" 
		&&  fam["generation"] == 37  ) 
			return ::valid_leave(me, dir);
		
		if( me->query("guilty") == 0 
		&&  me->query("id") != "seng bing" )
		{
			return notify_fail("ɮ����ס˵������δ����ɣ����ܽ������Ժ��\n");
		}
	}

	return ::valid_leave(me, dir);
}

