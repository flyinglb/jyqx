// /u/beyond/mr/duchuan2.c
// this is made by beyond
// update 1997.6.20
inherit ROOM;
void create()
{
	set("short", "�ɴ�");
	set("long", @LONG
һҶС�ۣ����Ҳ�������ߡ��˸��ˡ�һ����ʮ�����������
�ֳֳ���ݣ����ڴ�β�����س��Ŵ���
LONG
	);
        set("no_fight",1);

	setup();
}
void run(object ob)
{
       	if (environment(ob) == this_object())
       	ob->move(__DIR__"duchuan3", 1);
//	write("\nС���ںɻ����л�������,��һ����俴��С���������ˡ�\n\n");
}

void init()
{
       object ob = this_player();

    call_out("run", 10, ob);
}

