// yideng.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
    set_name("һ�ƴ�ʦ", ({"yideng-dashi", "dashi", "yideng"}));
    set("nickname", HIG "�ϵ�" NOR );
    set("gender", "����");
    set("age", 52);
    set("long", 
        "�����Ǻųơ��ϵۡ���һ�ƴ�ʦ�����������ˣ�����ѷλΪɮ��\n"
        "��ʦһ�����ƣ��������\n");
    set("attitude", "peaceful");
    set("class", "scholar");
	
    set("str", 21);
    set("int", 30);
    set("con", 26);
    set("dex", 30);

    set("qi", 3000);
    set("max_qi", 3000);
    set("jing", 3000);
    set("max_jing", 3000);
    set("neili", 3500);
    set("max_neili", 3500);
    set("jiali", 100);
	
    set("combat_exp", 1500000);
    set("score", 0);
	 
    set_skill("force", 150);             // �����ڹ�
    set_skill("finger", 170);            // ����ָ��
    set_skill("dodge", 150);             // ��������
    set_skill("parry", 150);             // �����м�
//    set_skill("liumai-shenjian", 200);   // ������
    set_skill("six-finger", 200);   // ������
    set_skill("taixuan-gong", 200);      // ̫����
    set_skill("lingxu-bu", 200);         // ���鲽
    set_skill("literate",150);           // ����ʶ��
	
    map_skill("force"  , "taixuan-gong");
    map_skill("finger" , "six-finger");
    map_skill("dodge"  , "lingxu-bu");
    map_skill("parry"  , "six-finger");

    prepare_skill("finger", "six-finger");

    create_family("����μ�", 17, "����");
    setup();

    carry_object("/clone/misc/cloth")->wear();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob=this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 2, ob);
        }
}

void greeting(object ob)
{
	object *obj, me=this_object();
	int i;

	obj = all_inventory(environment(me));
//һ�ƴ�ʦ������Ц�����Ż�ҩʦ���˹��ֵ�����ү�ӹ�����!
        command("nali huang");
        command("say �����ں�����֮���Σ������벻��֮�С�");
	for(i=0; i<sizeof(obj); i++)
	{
		if( obj[i]->query("id")=="huang-yaoshi")
                {
                    COMBAT_D->do_attack(me, obj[i], me->query_temp("weapon"), 0);
                    COMBAT_D->do_attack(me, obj[i], me->query_temp("weapon"), 0);
                }
	}
        return;
}

