//LUCAS 2000-6-18
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("����",({"lingxiao dizi","dizi"}));
        set("gender", "����");
        set("age", 20);
        set("long", 
               "����һ�������ǵ���ͨ���ӡ�\n");
        set("attitude", "peaceful");

        set("str", 30);
        set("con", 30);
        set("int", 30);
        set("dex", 30);
        set("neili", 500);
        set("max_neili", 500);
        set("max_jing", 400);
        set("jing", 400);
        set("max_qi", 800);
        set("qi", 800);
        set("jiali", 20);

        set("combat_exp", 20000);
        set("shen_type", 0);
        set("score", 50000);
        set("chat_chance", 10);
        set("chat_msg", ({
       "һ�������ǵ���С��˵������˵��ү�ӷ����ˣ����ѷ�ʦ��İ���ж����������֪�������Ǽ١�\n", 
       "����������Ц�����������˺ð��������Ӱ���һ�ε��۽�Ҳ���ÿ��ˣ���ð��\n", 
       "һ�������ǵ��Ӻ���һ��������ʦ��һ��˵���������ǵĽ���������˫��������Ҫ����Щ�������˼�ʶһ�¡�\n",
       "һ�������ǵ��Ӳ�м������ү�ӵĲ����������ģ����ǲ�֪���ɡ�\n",
       "�����ǵ��Ӻ���һ���������������Ʒ���ʹ��Ҫ���ˣ����ǻ�������·�ɡ�\n",
       "�����ǵ���ҡҡͷ�������������Ʒ���ʹ�����ˣ�ֻҪ���˽����ƣ�������ЩС����Ҳû�¡�\n",
       "һ�������ǵ��Ӵ��˸���Ƿ�����������ֵ������سǣ���㱻������\n",
       "һ�������ǵ��Ӵ��˴��֣����������Ҵ�ʦ���Ĺ�����͵��ƿ������ƣ��ٺ١���������Ĳ���\n",
       "һ�������ǵ��ӿ������ܣ�С��˵�����ϴ�л�̿�����ʱ�򣬴����Ǹ������֣���˵�ǳ��ְ�İ�����\n",
       "һ�������ǵ��Ӱ��˸����ƣ�����˵���䵱������ʲô����ү��˵�ˣ������о�������������������\n",
       "һ�������ǵ����ͳ�һƿ�ƣ��������ڣ������۾�˵����ү���Ǳ���ʦ�������ǰ����ˣ��ҵȻ��ȥ�����ȳ�����\n",
       "һ�������ǵ��ӵ�������һλ����˵��Ҫ������Σ��ͱ������õ������ư���\n",
       "һ�������ǵ��ӷ߷�˵�����Ǹ������֣��ϴξ���԰������Ҫ�������������ߺߺߣ�\n",
        }) );
        set_skill("unarmed", 50);
        set_skill("sword", 60);
        set_skill("force", 60);
        set_skill("parry", 50);
        set_skill("dodge", 60);
        set_skill("literate", 20);

        set_skill("xueshan-sword", 60);
        set_skill("bingxue-xinfa", 50);
        set_skill("snow-zhang", 40);
        set_skill("snowstep", 50);

        map_skill("sword", "xueshan-sword");
        map_skill("parry", "xueshan-sword");
        map_skill("force", "bingxue-xinfa");
        map_skill("unarmed", "snow-zhang");
        map_skill("dodge", "snowstep");

        create_family("������", 7, "����");
        setup();

        carry_object("/d/lingxiao/obj/icesword")->wield();        
        carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
        
        if( this_player()->query("family/master_id") == "bai zizai") {
                message_vision(HIC "����������$N����Ϊ��˵����ʦ�������˼Һã�\n" NOR, 
                this_player());
        }       
}

