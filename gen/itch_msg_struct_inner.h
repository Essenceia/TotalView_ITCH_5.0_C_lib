
struct {
u16_t itch_system_event_stock_locate;
u16_t itch_system_event_tracking_number;
u48_t itch_system_event_timestamp;
eSystemEvent itch_system_event_event_code;
}itch_system_event_data;

struct {
u16_t itch_stock_directory_stock_locate;
u16_t itch_stock_directory_tracking_number;
u48_t itch_stock_directory_timestamp;
char_8_t itch_stock_directory_stock;
eMarketCategory itch_stock_directory_market_category;
eFinancialStatusIndicator itch_stock_directory_financial_status_indicator;
u32_t itch_stock_directory_round_lot_size;
eRoundLotsOnly itch_stock_directory_round_lots_only;
eIssueClassification itch_stock_directory_issue_classification;
char_2_t itch_stock_directory_issue_sub_type;
eAuthenticity itch_stock_directory_authenticity;
eShortSaleThresholdIndicator itch_stock_directory_short_sale_threshold_indicator;
eIPOFlag itch_stock_directory_ipo_flag;
eLULDReferencePriceTier itch_stock_directory_luld_reference_price_tier;
eETPFlag itch_stock_directory_etp_flag;
u32_t itch_stock_directory_etp_leverage_factor;
eInverseIndicator itch_stock_directory_inverse_indicator;
}itch_stock_directory_data;

struct {
u16_t itch_stock_trading_action_stock_locate;
u16_t itch_stock_trading_action_tracking_number;
u48_t itch_stock_trading_action_timestamp;
char_8_t itch_stock_trading_action_stock;
eTradingState itch_stock_trading_action_trading_state;
char_t itch_stock_trading_action_reserved;
char_4_t itch_stock_trading_action_reason;
}itch_stock_trading_action_data;

struct {
u16_t itch_reg_sho_restriction_stock_locate;
u16_t itch_reg_sho_restriction_tracking_number;
u48_t itch_reg_sho_restriction_timestamp;
char_8_t itch_reg_sho_restriction_stock;
eRegSHOAction itch_reg_sho_restriction_reg_sho_action;
}itch_reg_sho_restriction_data;

struct {
u16_t itch_market_participant_position_stock_locate;
u16_t itch_market_participant_position_tracking_number;
u48_t itch_market_participant_position_timestamp;
char_4_t itch_market_participant_position_mpid;
char_8_t itch_market_participant_position_stock;
ePrimaryMarketMaker itch_market_participant_position_primary_market_maker;
eMarketMakerMode itch_market_participant_position_market_maker_mode;
eMarketParticipantState itch_market_participant_position_market_participant_state;
}itch_market_participant_position_data;

struct {
u16_t itch_mwcb_decline_level_stock_locate;
u16_t itch_mwcb_decline_level_tracking_number;
u48_t itch_mwcb_decline_level_timestamp;
price_8_t itch_mwcb_decline_level_level_1;
price_8_t itch_mwcb_decline_level_level_2;
price_8_t itch_mwcb_decline_level_level_3;
}itch_mwcb_decline_level_data;

struct {
u16_t itch_mwcb_status_stock_locate;
u16_t itch_mwcb_status_tracking_number;
u48_t itch_mwcb_status_timestamp;
eBreachedLevel itch_mwcb_status_breached_level;
}itch_mwcb_status_data;

struct {
u16_t itch_ipo_quoting_period_update_stock_locate;
u16_t itch_ipo_quoting_period_update_tracking_number;
u48_t itch_ipo_quoting_period_update_timestamp;
char_8_t itch_ipo_quoting_period_update_stock;
u32_t itch_ipo_quoting_period_update_ipo_quotation_release_time;
eIPOQuotationReleaseQualifier itch_ipo_quoting_period_update_ipo_quotation_release_qualifier;
price_4_t itch_ipo_quoting_period_update_ipo_price;
}itch_ipo_quoting_period_update_data;

struct {
u16_t itch_luld_auction_collar_stock_locate;
u16_t itch_luld_auction_collar_tracking_number;
u48_t itch_luld_auction_collar_timestamp;
char_8_t itch_luld_auction_collar_stock;
price_4_t itch_luld_auction_collar_auction_collar_reference_price;
price_4_t itch_luld_auction_collar_upper_auction_collar_price;
price_4_t itch_luld_auction_collar_lower_auction_collar_price;
u32_t itch_luld_auction_collar_auction_collar_extension;
}itch_luld_auction_collar_data;

struct {
u16_t itch_operational_halt_stock_locate;
u16_t itch_operational_halt_tracking_number;
u48_t itch_operational_halt_timestamp;
char_8_t itch_operational_halt_stock;
eMarketCode itch_operational_halt_market_code;
eOperationalHaltAction itch_operational_halt_operational_halt_action;
}itch_operational_halt_data;

struct {
u16_t itch_add_order_stock_locate;
u16_t itch_add_order_tracking_number;
u48_t itch_add_order_timestamp;
u64_t itch_add_order_order_reference_number;
eBuySellIndicator itch_add_order_buy_sell_indicator;
u32_t itch_add_order_shares;
char_8_t itch_add_order_stock;
price_4_t itch_add_order_price;
}itch_add_order_data;

struct {
u16_t itch_add_order_with_mpid_stock_locate;
u16_t itch_add_order_with_mpid_tracking_number;
u48_t itch_add_order_with_mpid_timestamp;
u64_t itch_add_order_with_mpid_order_reference_number;
eBuySellIndicator itch_add_order_with_mpid_buy_sell_indicator;
u32_t itch_add_order_with_mpid_shares;
char_8_t itch_add_order_with_mpid_stock;
price_4_t itch_add_order_with_mpid_price;
char_4_t itch_add_order_with_mpid_attribution;
}itch_add_order_with_mpid_data;

struct {
u16_t itch_order_executed_stock_locate;
u16_t itch_order_executed_tracking_number;
u48_t itch_order_executed_timestamp;
u64_t itch_order_executed_order_reference_number;
u32_t itch_order_executed_executed_shares;
u64_t itch_order_executed_match_number;
}itch_order_executed_data;

struct {
u16_t itch_order_executed_with_price_stock_locate;
u16_t itch_order_executed_with_price_tracking_number;
u48_t itch_order_executed_with_price_timestamp;
u64_t itch_order_executed_with_price_order_reference_number;
u32_t itch_order_executed_with_price_executed_shares;
u64_t itch_order_executed_with_price_match_number;
ePrintable itch_order_executed_with_price_printable;
price_4_t itch_order_executed_with_price_execution_price;
}itch_order_executed_with_price_data;

struct {
u16_t itch_order_cancel_stock_locate;
u16_t itch_order_cancel_tracking_number;
u48_t itch_order_cancel_timestamp;
u64_t itch_order_cancel_order_reference_number;
u32_t itch_order_cancel_cancelled_shares;
}itch_order_cancel_data;

struct {
u16_t itch_order_delete_stock_locate;
u16_t itch_order_delete_tracking_number;
u48_t itch_order_delete_timestamp;
u64_t itch_order_delete_order_reference_number;
}itch_order_delete_data;

struct {
u16_t itch_order_replace_stock_locate;
u16_t itch_order_replace_tracking_number;
u48_t itch_order_replace_timestamp;
u64_t itch_order_replace_original_order_reference_number;
u64_t itch_order_replace_new_order_reference_number;
u32_t itch_order_replace_shares;
price_4_t itch_order_replace_price;
}itch_order_replace_data;

struct {
u16_t itch_trade_stock_locate;
u16_t itch_trade_tracking_number;
u48_t itch_trade_timestamp;
u64_t itch_trade_order_reference_number;
eBuySellIndicator itch_trade_buy_sell_indicator;
u32_t itch_trade_shares;
char_8_t itch_trade_stock;
price_4_t itch_trade_price;
u64_t itch_trade_match_number;
}itch_trade_data;

struct {
u16_t itch_cross_trade_stock_locate;
u16_t itch_cross_trade_tracking_number;
u48_t itch_cross_trade_timestamp;
u64_t itch_cross_trade_shares;
char_8_t itch_cross_trade_stock;
price_4_t itch_cross_trade_cross_price;
u64_t itch_cross_trade_match_number;
eCrossType itch_cross_trade_cross_type;
}itch_cross_trade_data;

struct {
u16_t itch_broken_trade_stock_locate;
u16_t itch_broken_trade_tracking_number;
u48_t itch_broken_trade_timestamp;
u64_t itch_broken_trade_match_number;
}itch_broken_trade_data;

struct {
u16_t itch_net_order_imbalance_indicator_stock_locate;
u16_t itch_net_order_imbalance_indicator_tracking_number;
u48_t itch_net_order_imbalance_indicator_timestamp;
u64_t itch_net_order_imbalance_indicator_paired_shares;
u64_t itch_net_order_imbalance_indicator_imbalance_shares;
eImbalanceDirection itch_net_order_imbalance_indicator_imbalance_direction;
char_8_t itch_net_order_imbalance_indicator_stock;
price_4_t itch_net_order_imbalance_indicator_far_price;
price_4_t itch_net_order_imbalance_indicator_near_price;
price_4_t itch_net_order_imbalance_indicator_current_reference_price;
eCrossType itch_net_order_imbalance_indicator_cross_type;
ePriceVariationIndicator itch_net_order_imbalance_indicator_price_variation_indicator;
}itch_net_order_imbalance_indicator_data;

struct {
u16_t itch_retail_price_improvement_indicator_stock_locate;
u16_t itch_retail_price_improvement_indicator_tracking_number;
u48_t itch_retail_price_improvement_indicator_timestamp;
char_8_t itch_retail_price_improvement_indicator_stock;
eInterestFlag itch_retail_price_improvement_indicator_interest_flag;
}itch_retail_price_improvement_indicator_data;

struct {
char_20_t itch_end_of_snapshot_sequence_number;
}itch_end_of_snapshot_data;