//Room: majiu1.c ���
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","���");
      set("long",@LONG
���Ǳ���С�����ǣ����깩Ӧ���ʲ��ϡ�����ش��Ὦ���������
���ÿͣ�������Զ�����������ֵܿ���������ǻ����ǣ����Ǻ����տ���
������ι�����㣬�����������ˬˬ��һֱ�ź򵽿�����·����Ǿ�ľ��
�϶���һ����ľ��(paizi)��
    ����жѷ������Ѳ��ϣ�������һ����ۡ�
LONG);
      set("outdoors", "city2");
      set("no_fight", "1");
      set("no_beg", "1");
      set("objects", ([
	    "/d/city/npc/zaohongma": 1,
	    "/d/city/npc/huangbiaoma": 1,
	    "/d/city/npc/ziliuma": 1,
	    "/d/city/npc/camel": 1,
            __DIR__"npc/mafu": 1,
      ]));
      set("item_desc", ([
          "paizi": @TEXT
������ֻҪ�����һ�����������Ϳ��Թ͵�һƥ���ˡ�

ǰ��      ���ݳ�:  rideyz


TEXT]));
      set("exits",([ /* sizeof() == 1 */
          "south"      : __DIR__"beijiang",
      ]));
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
