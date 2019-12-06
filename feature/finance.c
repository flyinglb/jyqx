// finance.c

// can_afford() checks if this_object() can afford a price, it returns:
//
//      0:      cannot afford.
//      1:      can afford with proper money(coins).
//      2:      can afford, but don't have enough proper money(coins).
//
int can_afford(int amount)
{
        int total;
        object gold, silver, coin;

        gold = present("gold_money");
        silver = present("silver_money");
        coin = present("coin_money");

        total = 0;
        if( gold ) total += gold->value();
        if( silver ) total += silver->value();
        if( coin ) total += coin->value();

        if( total < amount ) return 0;

        if( coin ) amount -= (int)coin->value();
        if( amount <= 0 ) return 1;
        else if( amount % 100 ) return 2;

        if( silver ) amount -= (int)silver->value();
        if( amount <= 0 ) return 1;
        else if( amount % 10000 ) return 2;

        return 1;
}

int pay_money(int amount)
{
        int total;
        object gold, silver, coin;

        gold = present("gold_money");
        silver = present("silver_money");
        coin = present("coin_money");

        total = 0;
          if( gold ) { total += gold->value();destruct(gold); }
          if( silver ) { total += silver->value();destruct(silver); }
          if( coin ) { total += coin->value();destruct(coin); }

        if( total < amount ) return 0;
		total-=amount;

		if( total > 10000 ) {
            gold=new(GOLD_OB);
            if (!gold->move(this_player())) gold->move(environment(this_player()));
                gold->set_amount(total/10000);
            total %= 10000;
        }
        if( total > 100 ) {
			silver=new(SILVER_OB);
			if (!silver->move(this_player())) silver->move(environment(this_player()));
				silver->set_amount(total/100);
            total %= 100;
        }
        if( total > 0 ) {
			coin=new(COIN_OB);
			if (!coin->move(this_player())) coin->move(environment(this_player()));
				coin->set_amount(total);
        }
}
