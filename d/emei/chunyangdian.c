//Room: chunyangdian.c ������
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","������");
      set("long",@LONG
�������һǧ���ף������ľ�Դ䣬�ľ����ˡ���ǰ��һʯ��������ʯ��
��˵����������ɽʱ������������Ϣ�����ڴ˿��ݹ۶�����壬�����𶥣���
���ͱڣ�������ߡ�������������ˮ�֣������ǹ��Ƹ�
LONG);
      set("exits",([ /* sizeof() == 1 */
          "eastdown"  : __DIR__"guiyunge",
          "westup"    : __DIR__"shenshuian",
      ]));
      set("outdoors", "emei");
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
