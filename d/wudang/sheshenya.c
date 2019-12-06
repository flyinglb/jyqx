//Room: sheshenya.c ������
//Date: Sep 22 1997

inherit ROOM;

void create()
{
	set("short","������");
	set("long",@LONG
����һ���վ��������ͱڣ��ഫ������ڴ�����õ�������������դ����
��ֹ������ɱ������۵ĺ󳾡������������ȴ�����䵱������ϰ�Ṧ�ĺó�
�������������������(climb xuanya)�������Ṧ̫��Ŀɱ�����Ӵ��
LONG);
	set("exits",([ /* sizeof() == 1 */
		"east"     : __DIR__"nanyanfeng",
	]));
	set("outdoors", "wudang");
	set("no_clean_up", 0);
	setup();
//	replace_program(ROOM);
}
void init()
{
	add_action("do_climb", "climb");
}
int do_climb(string arg)
{
        object ob;
        int c_skill;
        ob = this_player();

        if (arg != "xuanya") return 0;
        c_skill=(int)ob->query_skill("dodge", 1);

        if (ob->query("qi")<50)
        {
                message_vision("$N̫���ˣ�û���������µ��ˡ�\n",ob);
                return 1; 
        }
        if (c_skill> 200)
        {
                message_vision("$N�Ṧ�����ˣ�����Ҳû���ˡ�\n",ob);
                return 1; 
        }
        if (c_skill< 100)
        {
                message_vision("$N�Ṧ̫���ˣ��޷���������������µġ�\n",ob);
                return 1; 
        }

        message_vision("$N�����������£������ݺἸ�Σ��о��������һЩ��\n",ob);
        ob->improve_skill("dodge", random(50*ob->query("int")));
        ob->receive_damage("qi", 25);
        return 1;
}
