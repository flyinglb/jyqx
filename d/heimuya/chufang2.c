//chufang1.c
inherit ROOM;
void create()
{
  set("short","����");
  set("long", @LONG
����ʥ���õĳ�����һλ������Ů������Ц�������������
��֬��������ǽ������һ����Ŀ������(note)��
LONG  );
  set("exits",([
      "west" : __DIR__"chitang",
  ]));
  set("item_desc",([
      "note" : "��������Ů�˸������ջ�ˮ��----->����Ⱥ��\n",
  ]));

  set("objects",([
      __DIR__"npc/shinu" : 1,
      __DIR__"obj/tea" : random(6),
      __DIR__"obj/sherou"  : random(4),
  ]));
//  set("no_clean_up", 0);
  setup();
}
int valid_leave(object me, string dir)
{
	if (( present("tea", me)||present("she rou", me))
	&&objectp(present("shi nu", environment(me))) )
	return notify_fail
	("��Ů��Ŀһ�������ߣ�û�ţ�\n");
	return ::valid_leave(me, dir);
}

