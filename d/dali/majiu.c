//Room: /d/dali/majiu.c
//Date: June. 29 1998 by Java

inherit ROOM;

void create()
{
      set("short","���");
      set("long",@LONG
���Ǿ�Ӫ���ϵ���ǣ����깩Ӧ���ʲ��ϡ���˵�˵���紾�ӣ�
����ֻҪ������������Ǿͻ����ǣ����Ǻ����տ���������ι����
�㣬��ϴˢ�ø�Ǭ������һֱ�ź򵽿��������·����������µ���
ľ���϶���һ����ľ��(paizi)��
    ����жѷ������Ѳ��ϣ�������һ����ۡ�
LONG);
      set("outdoors", "city");
      set("no_fight", "1");
      set("no_beg", "1");
      set("no_clean_up", 0);
      set("objects", ([
               "/d/city/npc/zaohongma": 1,
               "/d/city/npc/huangbiaoma": 1,
               "/d/city/npc/ziliuma": 1,
               __DIR__"npc/mafu": 1,
      ]));
      set("item_desc", ([
          "paizi": @TEXT
������ֻҪ�����һ�����������Ϳ��Թ͵�һƥ���ˡ�

ǰ��      ���ݳ�:  rideyz

TEXT]));
      set("exits",([ /* sizeof() == 1 */
          "east"  : __DIR__"bingying",
      ]));
      setup();
      replace_program(ROOM);
}
