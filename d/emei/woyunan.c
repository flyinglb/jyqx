//Room: woyunan.c ������
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","������");
      set("long",@LONG
�������Ա��и�����Ȫ����˵��ǰ������ˮ�˶���ɺԣ�����Ϊ֮�о���
����Ȫˮ���������������ֱ��Ƕù�̨���Ա��ǻ����֡�
LONG);
      set("objects", ([
           CLASS_D("emei") + "/xuan" : 1,
      ]));
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "out"        : __DIR__"dgtsheshenya",
          "northeast"  : __DIR__"jinding", 
          "southeast"  : __DIR__"huacangan", 
      ]));
//      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
