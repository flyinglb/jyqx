//Room: hcahoudian.c �����ֺ��
//Date: Oct. 2 1997 by That

inherit ROOM;
void do_chat();

void create()
{
      set("short","�����ֺ��");
      set("long",@LONG
���Ƕ���ɽ�����ֵĺ��Ƕ����������˴��̵��ӹ���ĵط������﹩
��һ���������������Կ�ǽ���ż���̫ʦ�Σ����Ϸ��ż������š���������
���򼸸�Ů���Ӵ����书��
LONG);
      set("objects", ([
           CLASS_D("emei") + "/miejue" : 1,
      ]));
      set("no_get_from", 1);
      set("no_get", 1);
      set("no_steal", 1);
      set("no_clean_up", 0);
      set("exits",([ /* sizeof() == 1 */
          "north"   : __DIR__"hcadadian", 
      ]));
      setup();
      replace_program(ROOM);
}
