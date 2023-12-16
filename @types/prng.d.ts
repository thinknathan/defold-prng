/** @noSelfInFile */

/**
 * Defold psuedo-random number generator extension using the Mulberry32 method.
 * @noResolution
 */
declare namespace prng {
	/**
	 * Sets `s` as the seed for the pseudo-random number generator. The resulting sequences of numbers will be identical when the seeds are identical.
	 * @param s
	 */
	export function set_seed(s: number): void;
	/**
	 * Requests an integer between 0 and `max`.
	 * @param max
	 */
	export function rand_int(max: number): number;
	/**
	 * Requests a floating point number between 0 and 1.
	 */
	export function rand_float(): number;
}
