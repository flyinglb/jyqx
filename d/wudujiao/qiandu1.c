// by mayue

inherit ROOM;

void create()
{
	set("short", "ǧ������");
	set("long", @LONG
�������嶾����������ĵط���ɽ������һ����Ȼ��ʯ������
�������Ŀ��������һ��ɽ�紵�������ŵ�һ����ζ������վ��
�����嶾�̵��ӡ� 
LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
//		"eastup" : __DIR__"wdsl5",
		"south" : __DIR__"wdsl4",
//		"westdown" : __DIR__"wdsl3",
		"north" : __DIR__"qiandu2",
	]));
        set("objects", ([
                  __DIR__"npc/dizi": 4,
	]));
    

	setup();
//	replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
    me=this_player();
   if(dir=="north")
      {
  if ((string)me->query("family/family_name")!="�嶾��"
        & objectp(present("di zi", environment(me))))
          return notify_fail("�嶾�̵��Ӻ�Ȼ��ס�㣬�����ȵ�����λ" +
           RANK_D->query_respect(me) + "��ͷ���Ե����ʲô��\n");
      }
  return ::valid_leave(me, dir);
}
