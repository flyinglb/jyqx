//Room: wanxingan.c ������
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","������");
      set("long",@LONG
̫��ƺ�������ǹ�����ʦ�����ġ�������ɽ����ɯ须��������źϳ�һ�䣬
Ҷ�Ӱ��ڻ��⣬��������������׶�ʢ��֮�����������Ժ�֮�߹�Ʒ�ʡ��ɴ�
�����ϱ����𶥣����������
LONG);
      set("objects", ([
           CLASS_D("emei") + "/jia" : 1,
      ]));
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "eastdown"  : __DIR__"jieyindian",
          "southup"   : __DIR__"jinding",
      ]));
//      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
