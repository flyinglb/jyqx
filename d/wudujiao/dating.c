// by mayue


inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǹ����Ĵ������ߴ��������һ�˶��ϱ���������������ƽ�ս�
���ټ����������µĵط����������й�������ʥ--���ߣ�֩�룬��򼣬Ы��
��ܵĻ��񡣼�λ������������������ ��
LONG
	);
//      set("outdoors", "wudujiao");
//      set("sleep_room", 1);
//      set("no_fight", 1);
        set("valid_startroom", 1);

	set("exits", ([
		"east" : __DIR__"huayuan1",
		"south" : __DIR__"jingshi",
		"west" : __DIR__"lianwu",
		"north" : __DIR__"shufang",
	]));
        set("objects", ([
               __DIR__"npc/qiyunao": 1,
               __DIR__"npc/panxiuda": 1,
               __DIR__"npc/cenqisi": 1,
	]));
    

	setup();
      "/clone/board/wudu_b"->foo();
//	replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
    me=this_player();
   if(dir=="east"||dir=="north"||dir=="south")
      {
  if ((string)me->query("family/family_name")!="�嶾��"
        & objectp(present("qi yunao", environment(me))))
          return notify_fail("���ư�����һ�Σ���Ȼ��ס�㣬����˵������λ" +
           RANK_D->query_respect(me) + "���Ǳ��̵��ӣ����ý��뱾�̽��ء�\n");
      }
  return ::valid_leave(me, dir);
}

