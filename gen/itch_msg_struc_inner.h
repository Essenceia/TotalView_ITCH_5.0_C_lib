
struct {
u16_t itch_system_event_stock_locate : 2;
u16_t itch_system_event_tracking_number : 2;
u48_t itch_system_event_timestamp : 6;
eSystemEvent itch_system_event_event_code : 1;
}itch_system_event_data;

struct {
u16_t itch_stock_directory_stock_locate : 2;
u16_t itch_stock_directory_tracking_number : 2;
u48_t itch_stock_directory_timestamp : 6;
char_8_t itch_stock_directory_stock : 8;
eMarketCategory itch_stock_directory_market_category : 1;
eFinancialStatusIndicator itch_stock_directory_financial_status_indicator : 1;
u32_t itch_stock_directory_round_lot_size : 4;
eRoundLotsOnly itch_stock_directory_round_lots_only : 1;
eIssueClassification itch_stock_directory_issue_classification : 1;
char_2_t itch_stock_directory_issue_sub_type : 2;
eAuthenticity itch_stock_directory_authenticity : 1;
eShortSaleThresholdIndicator itch_stock_directory_short_sale_threshold_indicator : 1;
eIPOFlag itch_stock_directory_ipo_flag : 1;
eLULDReferencePriceTier itch_stock_directory_luld_reference_price_tier : 1;
eETPFlag itch_stock_directory_etp_flag : 1;
u32_t itch_stock_directory_etp_leverage_factor : 4;
eInverseIndicator itch_stock_directory_inverse_indicator : 1;
}itch_stock_directory_data;

struct {
u16_t itch_stock_trading_action_stock_locate : 2;
u16_t itch_stock_trading_action_tracking_number : 2;
u48_t itch_stock_trading_action_timestamp : 6;
char_8_t itch_stock_trading_action_stock : 8;
eTradingState itch_stock_trading_action_trading_state : 1;
char_t itch_stock_trading_action_reserved : 1;
char_4_t itch_stock_trading_action_reason : 4;
}itch_stock_trading_action_data;

struct {
u16_t itch_reg_sho_restriction_stock_locate : 2;
u16_t itch_reg_sho_restriction_tracking_number : 2;
u48_t itch_reg_sho_restriction_timestamp : 6;
char_8_t itch_reg_sho_restriction_stock : 8;
eRegSHOAction itch_reg_sho_restriction_reg_sho_action : 1;
}itch_reg_sho_restriction_data;

struct {
u16_t itch_market_participant_position_stock_locate : 2;
u16_t itch_market_participant_position_tracking_number : 2;
u48_t itch_market_participant_position_timestamp : 6;
char_4_t itch_market_participant_position_mpid : 4;
char_8_t itch_market_participant_position_stock : 8;
ePrimaryMarketMaker itch_market_participant_position_primary_market_maker : 1;
eMarketMakerMode itch_market_participant_position_market_maker_mode : 1;
eMarketParticipantState itch_market_participant_position_market_participant_state : 1;
}itch_market_participant_position_data;

struct {
u16_t itch_mwcb_decline_level_stock_locate : 2;
u16_t itch_mwcb_decline_level_tracking_number : 2;
u48_t itch_mwcb_decline_level_timestamp : 6;
price_8_t itch_mwcb_decline_level_level_1 : 8;
price_8_t itch_mwcb_decline_level_level_2 : 8;
price_8_t itch_mwcb_decline_level_level_3 : 8;
}itch_mwcb_decline_level_data;

struct {
u16_t itch_mwcb_status_stock_locate : 2;
u16_t itch_mwcb_status_tracking_number : 2;
u48_t itch_mwcb_status_timestamp : 6;
eBreachedLevel itch_mwcb_status_breached_level : 1;
}itch_mwcb_status_data;

struct {
u16_t itch_ipo_quoting_period_update_stock_locate : 2;
u16_t itch_ipo_quoting_period_update_tracking_number : 2;
u48_t itch_ipo_quoting_period_update_timestamp : 6;
char_8_t itch_ipo_quoting_period_update_stock : 8;
u32_t itch_ipo_quoting_period_update_ipo_quotation_release_time : 4;
eIPOQuotationReleaseQualifier itch_ipo_quoting_period_update_ipo_quotation_release_qualifier : 1;
price_4_t itch_ipo_quoting_period_update_ipo_price : 4;
}itch_ipo_quoting_period_update_data;

struct {
u16_t itch_luld_auction_collar_stock_locate : 2;
u16_t itch_luld_auction_collar_tracking_number : 2;
u48_t itch_luld_auction_collar_timestamp : 6;
char_8_t itch_luld_auction_collar_stock : 8;
price_4_t itch_luld_auction_collar_auction_collar_reference_price : 4;
price_4_t itch_luld_auction_collar_upper_auction_collar_price : 4;
price_4_t itch_luld_auction_collar_lower_auction_collar_price : 4;
u32_t itch_luld_auction_collar_auction_collar_extension : 4;
}itch_luld_auction_collar_data;

struct {
u16_t itch_operational_halt_stock_locate : 2;
u16_t itch_operational_halt_tracking_number : 2;
u48_t itch_operational_halt_timestamp : 6;
char_8_t itch_operational_halt_stock : 8;
eMarketCode itch_operational_halt_market_code : 1;
eOperationalHaltAction itch_operational_halt_operational_halt_action : 1;
}itch_operational_halt_data;

struct {
u16_t itch_add_order_stock_locate : 2;
u16_t itch_add_order_tracking_number : 2;
u48_t itch_add_order_timestamp : 6;
u64_t itch_add_order_order_reference_number : 8;
eBuySellIndicator itch_add_order_buy_sell_indicator : 1;
u32_t itch_add_order_shares : 4;
char_8_t itch_add_order_stock : 8;
price_4_t itch_add_order_price : 4;
}itch_add_order_data;

struct {
u16_t itch_add_order_with_mpid_stock_locate : 2;
u16_t itch_add_order_with_mpid_tracking_number : 2;
u48_t itch_add_order_with_mpid_timestamp : 6;
u64_t itch_add_order_with_mpid_order_reference_number : 8;
eBuySellIndicator itch_add_order_with_mpid_buy_sell_indicator : 1;
u32_t itch_add_order_with_mpid_shares : 4;
char_8_t itch_add_order_with_mpid_stock : 8;
price_4_t itch_add_order_with_mpid_price : 4;
char_4_t itch_add_order_with_mpid_attribution : 4;
}itch_add_order_with_mpid_data;

struct {
u16_t itch_order_executed_stock_locate : 2;
u16_t itch_order_executed_tracking_number : 2;
u48_t itch_order_executed_timestamp : 6;
u64_t itch_order_executed_order_reference_number : 8;
u32_t itch_order_executed_executed_shares : 4;
u64_t itch_order_executed_match_number : 8;
}itch_order_executed_data;

struct {
u16_t itch_order_executed_with_price_stock_locate : 2;
u16_t itch_order_executed_with_price_tracking_number : 2;
u48_t itch_order_executed_with_price_timestamp : 6;
u64_t itch_order_executed_with_price_order_reference_number : 8;
u32_t itch_order_executed_with_price_executed_shares : 4;
u64_t itch_order_executed_with_price_match_number : 8;
ePrintable itch_order_executed_with_price_printable : 1;
price_4_t itch_order_executed_with_price_execution_price : 4;
}itch_order_executed_with_price_data;

struct {
u16_t itch_order_cancel_stock_locate : 2;
u16_t itch_order_cancel_tracking_number : 2;
u48_t itch_order_cancel_timestamp : 6;
u64_t itch_order_cancel_order_reference_number : 8;
u32_t itch_order_cancel_cancelled_shares : 4;
}itch_order_cancel_data;

struct {
u16_t itch_order_delete_stock_locate : 2;
u16_t itch_order_delete_tracking_number : 2;
u48_t itch_order_delete_timestamp : 6;
u64_t itch_order_delete_order_reference_number : 8;
}itch_order_delete_data;

struct {
u16_t itch_order_replace_stock_locate : 2;
u16_t itch_order_replace_tracking_number : 2;
u48_t itch_order_replace_timestamp : 6;
u64_t itch_order_replace_original_order_reference_number : 8;
u64_t itch_order_replace_new_order_reference_number : 8;
u32_t itch_order_replace_shares : 4;
price_4_t itch_order_replace_price : 4;
}itch_order_replace_data;

struct {
u16_t itch_trade_stock_locate : 2;
u16_t itch_trade_tracking_number : 2;
u48_t itch_trade_timestamp : 6;
u64_t itch_trade_order_reference_number : 8;
eBuySellIndicator itch_trade_buy_sell_indicator : 1;
u32_t itch_trade_shares : 4;
char_8_t itch_trade_stock : 8;
price_4_t itch_trade_price : 4;
u64_t itch_trade_match_number : 8;
}itch_trade_data;

struct {
u16_t itch_cross_trade_stock_locate : 2;
u16_t itch_cross_trade_tracking_number : 2;
u48_t itch_cross_trade_timestamp : 6;
u64_t itch_cross_trade_shares : 8;
char_8_t itch_cross_trade_stock : 8;
price_4_t itch_cross_trade_cross_price : 4;
u64_t itch_cross_trade_match_number : 8;
eCrossType itch_cross_trade_cross_type : 1;
}itch_cross_trade_data;

struct {
u16_t itch_broken_trade_stock_locate : 2;
u16_t itch_broken_trade_tracking_number : 2;
u48_t itch_broken_trade_timestamp : 6;
u64_t itch_broken_trade_match_number : 8;
}itch_broken_trade_data;

struct {
u16_t itch_net_order_imbalance_indicator_stock_locate : 2;
u16_t itch_net_order_imbalance_indicator_tracking_number : 2;
u48_t itch_net_order_imbalance_indicator_timestamp : 6;
u64_t itch_net_order_imbalance_indicator_paired_shares : 8;
u64_t itch_net_order_imbalance_indicator_imbalance_shares : 8;
eImbalanceDirection itch_net_order_imbalance_indicator_imbalance_direction : 1;
char_8_t itch_net_order_imbalance_indicator_stock : 8;
price_4_t itch_net_order_imbalance_indicator_far_price : 4;
price_4_t itch_net_order_imbalance_indicator_near_price : 4;
price_4_t itch_net_order_imbalance_indicator_current_reference_price : 4;
eCrossType itch_net_order_imbalance_indicator_cross_type : 1;
ePriceVariationIndicator itch_net_order_imbalance_indicator_price_variation_indicator : 1;
}itch_net_order_imbalance_indicator_data;

struct {
u16_t itch_retail_price_improvement_indicator_stock_locate : 2;
u16_t itch_retail_price_improvement_indicator_tracking_number : 2;
u48_t itch_retail_price_improvement_indicator_timestamp : 6;
char_8_t itch_retail_price_improvement_indicator_stock : 8;
eInterestFlag itch_retail_price_improvement_indicator_interest_flag : 1;
}itch_retail_price_improvement_indicator_data;

struct {
char_20_t itch_end_of_snapshot_sequence_number : 20;
}itch_end_of_snapshot_data;
