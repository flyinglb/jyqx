//Room: majiu2.c ���
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","���");
      set("long",@LONG
���ǲ���ߵ���ǣ����깩Ӧ���ʲ��ϡ���˵�˵���紾�ӣ�����ǻ��
��ǣ����Ǻ����տ���������ι�����㣬��ϴˢ�ø�Ǭ������һֱ�ź򵽿���
��·������жѷ������Ѳ��ϣ�������һ����ۡ�
    ��������µ���ľ���϶���һ����ľ��(paizi)��
LONG);
      set("outdoors", "city");
      set("no_fight", "1");
      set("no_beg", "1");
      set("objects", ([
          "/d/city/npc/zaohongma": 1,
          "/d/city/npc/huangbiaoma": 1,
          "/d/city/npc/ziliuma": 1,
          "/d/city/npc/camel": 1,
          __DIR__"npc/mafu2": 1,
      ]));
      set("item_desc", ([
          "paizi": @TEXT
������ֻҪ�����һ�����������Ϳ��Թ͵�һƥ���ˡ�

ǰ��      ����ɽ��: rideem

TEXT]));
      set("exits",([ /* sizeof() == 1 */
          "south"    : __DIR__"huayanding",
      ]));
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
