//Room: yuzhengong.c ���湬
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","���湬");
      set("long",@LONG
�����ǽ����䵱ɽ�ĵ�һ���������湬�����ޱȣ�����ǧ��ʳ�ޣ�
�ǽ���͵�һ��Ъ�Ŵ��������������ڴ˽�����������˹��й�������
�����������������˱չ��Ѿã����˲�֪���Ƿ������˼䣬��䴫˵
���ѵõ����ţ�����Ĥ�ݡ�
LONG);
      set("objects", ([
           CLASS_D("wudang") +"/zhixiang": 1,
      ]));
      set("outdoors", "wudang");
      set("exits",([ /* sizeof() == 1 */
          "northdown": __DIR__"shijie1",
          "southup"  : __DIR__"wdbl",
      ]));
//      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
