
inherit NPC;

void create()
{
        set_name(HIW"����"NOR, ({"Netbai"}));
	set("nickname",HIR"��"+HIW+"����¥"+HIR+"��"+HIG+"��¥�� "+HIY+"��ɷ����"NOR);
	set("gender", "����");
	set("age", 30);
	set("per", 30);
	set("long", 
                  "�������ڱ�MUD�����������ˣ���֪����������ô�쵽��������\n"
                  "Ƣ���ã���������ͦ�����ټ�������ʱ��Ҫǧ��С�ĵ㣡\n");
                             
	setup();
        
	carry_object("/d/city2/obj/jinduan")->wear();
}
