//Room: lengsl4.c ��ɼ��
//Date: Oct. 2 1997 by That

inherit ROOM;
void create()
{
      set("short","��ɼ��");
      set("long",@LONG
����һƬ������յ���ɼ�֡�����Ҳ�ϱ�����������ɼ������һ�飬�ÿ�
֦��Ҷï����һ�����ɡ��������գ��������ڵ�˿��Ҳ�ޡ������Ϻ��Ŀ�
֦��Ҷ����Ȼ�οͺ���̤��˴���
LONG);
      set("exits",([ /* sizeof() == 1 */
          "southwest" : __DIR__"bashisipan3",
          "northdown" : __DIR__"lengsl3",
          "southeast" : __DIR__"jieyindian",
      ]));
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
