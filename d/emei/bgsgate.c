//Room: bgsgate.c ������ɽ��
//Date: Oct. 2 1997 by That

inherit ROOM;
string look_gate();

void create()
{
      set("short","������ɽ��");
      set("long",@LONG
������Ϊ���ҳ���֮�Ż���ɽ��(gate)����һ����ҡ������骻�������
����ӳ���ɴ�һ·�����Ͽ�ʼ�Ƕ���ɽ��������ɽ��һ�������ʯ��·��
LONG);
      set("outdoors", "emei");
      set("item_desc", ([
          "gate" : (: look_gate :),
      ]));
      set("objects", ([
               __DIR__+"npc/guest": 1,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "northdown" : __DIR__"qsjie2",
          "west"      : __DIR__"bgs",
      ]));
//      set("no_clean_up", 0);
      setup();
}
string look_gate()
{
      return
"�����������������աաաաաաաաաաաաաաաա�\n"
"�����������������աա��������������������������ա�\n"
"�����������������աա������������������¡������ա�\n"
"�����������������աա��������������������������ա�\n"
"�����������������աաաաաաաաաաաաաաաա�\n";
}
