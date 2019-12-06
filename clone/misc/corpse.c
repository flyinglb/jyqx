// corpse.c
//modified by cjw 991114

inherit ITEM;

int decayed;

void create()
{
        set_name("����ʬ��", ({ "corpse" })); 
        set("long", "����һ������ʬ�塣\n");
        set("unit", "��" );
        if( clonep(this_object()) ) call_out("decay", 120, 1);
        decayed = 0;
}

int is_corpse() { return decayed < 2; }
int is_character() { return decayed < 1; }
int is_container() { return 1; }

string short() { return name() + "(" + capitalize(query("id")) + ")"; }

void decay(int phase)
{
        object ob;
        decayed = phase;
        ob = environment();
        switch(phase) {
                case 1: 
                        tell_room( ob,query("name") + "��ʼ�����ˣ�����һ�����ŵĶ����\n" );
                        switch(query("gender")) {
                                case "����":
                                        set_name("���õ���ʬ", ({ "corpse", "ʬ��" }) );
                                case "Ů��":
                                        set_name("���õ�Ůʬ", ({ "corpse", "ʬ��" }) );
                                default:
                                        set_name("���õ�ʬ��", ({ "corpse", "ʬ��" }) );
                        }
                        set("long",     "���ʬ����Ȼ�Ѿ�����������һ��ʱ���ˣ���ɢ����һ�ɸ�ʬ��ζ����\n");
                        call_out("decay", 120, phase + 1);
                        break;
                case 2:
                        tell_room(ob, query("name") + "���紵Ǭ�ˣ����һ�ߺ��ǡ�\n" );
                        set_name("һ�߿�Ǭ�ĺ���", ({ "skeleton", "����" }) );
                        set("long", "�⸱�����Ѿ���������ܾ��ˡ�\n");
                        call_out("decay", 60, phase + 1);
                        break;
                case 3:
                        tell_room( ob, "һ��紵������" + query("name") + "���ɹǻҴ�ɢ�ˡ�\n" );
                        if( ob ) {
                                object *inv;
                                int i;
                                
                                ob->add_encumbrance( - query_weight());
                                inv = all_inventory(this_object());
                                for(i=0; i<sizeof(inv); i++) 
                                      {
                                        if (living(inv[i]))
                                        {
                                 if (ob->query("combat_exp")) inv[i]->move_relic(environment(ob));
                                          else inv[i]->move_relic(ob);
                                        }
                                        else inv[i]->move_relic(ob);
                                      }
                        }
                        destruct(this_object());
                        break;
        }
}

