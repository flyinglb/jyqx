//Room: zhongfengsi.c �з���
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","�з���");
      set("long",@LONG
�з����ڰ��Ʒ��£�ʼ���ڽ�����ԭΪ���ۡ���˵���ڵĵ���ÿ��������
���ն������ɽ��һ����������Ϊ�������ɡ������и�����������������ʦ��
ɱ��������������ʿ��ʼ֪�ϵ����м����ѣ���Ը���ŷ�̣��Ӵ˸Ĺ�Ϊ�¡�
���������ɵ������󣬶�������ˮ�֡�
LONG);
      set("objects", ([
               __DIR__+"npc/guest": 1,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "northwest"    : __DIR__"qingyinge",
          "eastdown"     : __DIR__"shenshuian",
      ]));
      set("outdoors", "emei");
//      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
