// Room: /guiyun/huating.c
// Date: Nov.18 1998 by Winder

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ���ķ��͵���ͤ��û�����ң���������ľ�������Ϲ���
��ȱ�˰��ڵġ�ʫ�ʡ�(poem)�����ڰ����˼������Ρ�һ��Ѿ����
��Ĩ�����档
LONG );
        set("outdoors", "guiyun");
//	set("no_clean_up", 0);

	set("exits", ([
		"north" : __DIR__"huayuan",
		"south" : __DIR__"dating",
		"east"  : __DIR__"nanxiangfang",
		"west"  : __DIR__"nvxiangfang",
	]));
	set("item_desc", ([
		"poem" :
"
      ������             ������
      ������             ��  ��
      ����             ��  ��
      ���Щ�             ��  ��
      ���ũ�             ��  ��
      ������             ��  ��
      ��ƶ��             ��  ��
      ���婦             ��  ��
      ���ũ�             ��  ��
      ������             ��  ��
      ���ҩ�             ��  ��
      ������             ������
",
	]));
	set("objects", ([
		__DIR__"npc/xiaolan" : 1,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "�һ���") &&
		(dir == "east" || dir == "west") ) 
		return notify_fail("����ׯ������ͣ��㲻��ס�����\n");
	if (me->query("gender") != "����" && dir == "east") 
		return notify_fail("��Ů�б��뵽����ס��\n");

	if (me->query("gender") != "Ů��" && dir == "west") 
		return notify_fail("��Ů�б��뵽����ס��\n");

	return ::valid_leave(me, dir);
}
