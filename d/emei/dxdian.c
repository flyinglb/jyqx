//Room: dxdian.c ���۵�
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","���۵�");
      set("long",@LONG
�����Ǳ����´��۵�������Ƕ���ɽ�����Ժ֮һ�����۵��ڹ��Ž��
�Ӳӵķ�������������
LONG);
      set("objects", ([
               __DIR__+"npc/guest": 2,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "west"     : __DIR__"bgschanfang",
          "out"      : __DIR__"bgs",
          "north"    : __DIR__"cangjinglou",
      ]));
//      set("no_clean_up", 0);
      setup();
}
int valid_leave(object me, string dir)
{
    mapping myfam;
    me = this_player();
    myfam = (mapping)me->query("family");
    if ((!myfam || (myfam["family_name"] != "������")) && (dir == "west"))
      return notify_fail("����������ֻ�Ӵ����ҵ��ӣ���Ҫ�ǳ�������ڴ˶����ע��ɡ�\n");
    else  return 1;
}
