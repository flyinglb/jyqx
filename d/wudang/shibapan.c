//Room: shibapan.c ʮ����
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","ʮ����");
      set("long",@LONG
����һ���ܴ��б�£��׳�ʮ���̣���ʯ��һ��һ����ֱ���ϣ��ķѽ�����
�����������񣬹չ�����������ʮ��֮������������
LONG);
      set("exits",([ /* sizeof() == 1 */
          "northdown"  : __DIR__"shiliang",
          "southup"    : __DIR__"shijie2",
      ]));
      set("outdoors", "wudang");
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
